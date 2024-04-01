#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command_history[200][200];
int cnt = 1;

int main(){
	
	while(1){
		char input[200];
		printf("SSAFY > ");
		scanf("%s", input);

		if (strcmp("exit", input) == 0)
			break;
		else if (strcmp("date", input) == 0){
			system("date");
			strcpy(command_history[cnt], input);
			cnt++;	
		}
		else if (strcmp("uptime", input) == 0){
			system("uptime");
			strcpy(command_history[cnt], input);
			cnt++;
		}	
		else if (strcmp("ls",input) == 0){
			system("ls -al");
			strcpy(command_history[cnt], input);
			cnt++;
		}
			
		// history
		else if (strcmp("history",input) == 0){
			strcpy(command_history[cnt], input);
			cnt++;
			for(int i=1; i < cnt; i++){
				printf("%d %s\n", i, command_history[i]);
			}
			
			printf("SSAFY > ");
			char history_command1[200], history_command2[200];
			scanf("%s", history_command1);
		
			if (strcmp("!", history_command1) == 0){
				int temp;
				scanf("%d", &temp);
				if (temp < cnt)
					system(command_history[temp]);
			}
			
			else if (strcmp("hclear", history_command1) == 0){
				memset(command_history, '\n' , sizeof(command_history));
				cnt = 1;
			
			}
			else{
				printf("wrong history command\n");
			}
			
		
		}
		else
			printf("ERROR\n");
	}


	return 0;
} 
