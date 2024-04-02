#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void alrm_handler(){
    printf("No input received. persin process terminate \n");
    exit(1);
}


int main(int argc, char* argv[]) {
    //firmware 먼저 실행해서 pid를 확인하기.
    pid_t target_pid = atoi(argv[1]);
    printf("%d process is target\n", atoi(argv[1]));
	
    signal(SIGALRM, alrm_handler);    				// sigalam의 핸들러 등록
    printf("You must enter input in 3 seconds... \n\n");

    char userInput[100];
    while(1){
  	alarm(3);
  	printf("user input >>");
  	scanf("%s", userInput);
    	
    	if (strcmp(userInput, "1") == 0){
  	    int ret = kill(target_pid, SIGUSR1);
  	    alarm(3);
		    if (ret == 0) {
					printf("%d <- signal transmit!\n", target_pid);
			  } 
		    else {
					printf("Fail!\n");
		    }
	    }
    	
    	else if (strcmp(userInput, "2") == 0){
  	    int ret = kill(target_pid, SIGUSR2);
  	    alarm(3);
		    if (ret == 0) {
					printf("%d <- signal transmit!\n", target_pid);
		    } 
		    else {
					printf("Fail!\n");
		    }
    	}
    	
    	else if (strcmp(userInput, "3") == 0){
        int ret = kill(target_pid, SIGTERM);
        alarm(3);
  	    if (ret == 0) {
					printf("%d <- signal transmit!\n", target_pid);
		    } 
		    else {
					printf("Fail!\n");
		    }
	}
	
    	else if (strcmp(userInput, "exit") == 0){
		    printf("\npersin process terminate\n");
		    exit(1);
    	  break;
    	} 
    	
    	else {
    	    printf("wrong command\n");	
    	}
    }
     

    printf("\n\npersin process terminate\n");

    return 0;
}
