
#include <stdio.h>
#include <stdlib.h>
#include "inqueue.h"

int main(void ){
    char value[10];
    QueueInit();
    printf("Enter a number: ");
    scanf("%s",value);
    int v=atoi(value);
    while (v>0){
        QueueEnqueue(v%2);
        v=v/2;
    }
    while (!QueueIsEmpty()){
        printf("%d",QueueDequeue());
    }
    return 0;
}