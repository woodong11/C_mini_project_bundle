//client 코드

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>       
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

const char *SERVER_IP;
const char *SERVER_PORT;

int client_sock;
void interrupt(int arg){
	printf("\nYou typped Ctrl + C\n");
	printf("Bye\n");

	close(client_sock);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc != 3){
		printf("ERROR: need two main argument: IP num, PORT num\n");
		exit(1);
		return 1;
	}
	SERVER_IP = argv[1];
	SERVER_PORT = argv[2];
	signal(SIGINT, interrupt);

	client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (client_sock == -1){
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}
	//printf("Socket Create!\n");

	struct sockaddr_in server_addr = {0};
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	server_addr.sin_port = htons(atoi(SERVER_PORT));
	
	socklen_t server_addr_len = sizeof(server_addr);

	if (connect(client_sock, (struct sockaddr *)&server_addr, server_addr_len) == -1){
		printf("ERROR :: 2_Connect Error\n");
		exit(1);
	}
	//printf("Connect Success!\n");
		

	////////////////// 통신부분 //////////////////
	char buf[100];
	int flag = 0;	// flag = 1: send, flag = 0: recieve 
	
	while (1){
		memset(buf, 0, 100);
		
		if (flag == 1){
			// send to server
			printf("write message to server >> ");
			scanf("%s", buf);
			if (!strcmp(buf, "exit")){
				write(client_sock, buf, strlen(buf));
				break;
			}
			write(client_sock, buf, strlen(buf));
			flag = 0;
		}
		
		else{
			memset(buf, 0, 100);
			int len = read(client_sock, buf, 99);
			if (len == 0){
				printf("INFO :: Server Disconnected\n");
				break;
			}
			
			// 제대로 읽었을 경우 
			if (atoi(buf) == 0)
				printf("server sent: %s\n", buf);
			else
				printf("server sent * 2: %d\n", atoi(buf)*2);
			

			flag = 1;
		}
	}
	///////////////////////////////////////////////


	close(client_sock);
	//printf("Logout\n");
	return 0;
}
