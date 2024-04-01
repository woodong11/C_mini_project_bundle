#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


int coin;
int pthreadNum;
int oldNum;
int queue[1000]; 			// 큐로 사용할 배열
int frontIdx = 0, backIdx = 0;

pthread_t tid[1000];
pthread_mutex_t mlock;

void *getCoin(){
    while(1){
    	pthread_mutex_lock(&mlock);
    	coin++;
    	usleep(100000);
    	pthread_mutex_unlock(&mlock);
     }
}

void push(int tid) {
    queue[backIdx] = tid; 
    backIdx++;
}

int pop() {
    if (frontIdx == backIdx) return -1; 	// 큐가 비었으면 -1
    int ret = queue[frontIdx]; 	        // 가장 오래된 쓰레드 ID 반환
    frontIdx++;
    return ret;
}

int main() {
    char inputStr[10];

    printf("##############################################################\n\n");
    printf("            welcome_dongwoo_coin_mining_machine!!             \n");
    printf("            usable command: show, add, del, exit              \n\n");
    printf("##############################################################\n\n");

    while (1) {
        printf("ssafy>> ");
        scanf("%s", inputStr);

        if (strcmp(inputStr, "show") == 0) {
            printf("current coins: %d\n", coin);
        } 
        
        else if (strcmp(inputStr, "add") == 0) {
            int num = backIdx; 
            pthread_create(&tid[num], NULL, getCoin, NULL);
            push(num); 
            printf("add machine %d\n", num);
        } 
        
        else if (strcmp(inputStr, "del") == 0) {
            int num = pop();                             	   // 큐에서 가장 오래된 쓰레드 번호 
            if (num != -1) {
                pthread_cancel(tid[num]);
                //pthread_join(tid[num], NULL);                    // 쓰레드 종료
                printf("machine %d has deleted\n", num);
            } else {
                printf("No machine to delete\n");
            }
        } 
        
        else if (strcmp(inputStr, "exit") == 0) {
            printf("exit\n");
            return 0;
        } 
        
        else {
            printf("wrong command\n");
        }
    }

    return 0;
}
