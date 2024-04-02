#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigFunc1(int num){
    printf("[Button Clicked] \n");
}

void sigFunc2(int num){
    system("clear");
    printf("RESET");
    printf("\n");
}

void sigFunc3(int num){
    printf("BYE \n");
    exit(0);
}

int main(){
    // signal들 등록 
    signal(SIGUSR1, sigFunc1);          
    signal(SIGUSR2, sigFunc2);
    signal(SIGTERM, sigFunc3);

    pid_t pid = getpid();
    printf("My PID : %d\n", pid);

    while(1) {
    	for(char i = 'A'; i <= 'Z'; i++){
	    	printf("%c\n",i);
				usleep(100000);
    	}
    	for(char i = 'Z'; i >= 'A'; i--){
	    	printf("%c\n",i);
				usleep(100000);
    	}
    
    }
    return 0;
}
