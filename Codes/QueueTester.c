//
// Created by siyu wang on 2020/9/19.
//

// Integer Stack ADO tester ... COMP9024 20T2
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int main(void) {
    int i, n;
    char str[BUFSIZ];

    QueueInit();

    printf("Enter a positive number: ");
    scanf("%s", str);
    if ((n = atoi(str)) > 0) {    // convert to int and test if positive
        for (i = 0; i < n; i++) {
            printf("Enter a number: ");
            scanf("%s", str);
            QueueEnqueue(atoi(str));
        }
    }

    /* NEEDS TO BE COMPLETED */
    while (!QueueIsEmpty()) {
        printf("%d\n", QueueDequeue());
    }

    int i1, n1;
    char str1[BUFSIZ];

    printf("Enter a positive number: ");
    scanf("%s", str1);
    if ((n1 = atoi(str1)) > 0) {    // convert to int and test if positive
        for (i1 = 0; i1 < n1; i1++) {
            printf("Enter a number: ");
            scanf("%s", str1);
            QueueEnqueue(atoi(str1));
        }
    }

    /* NEEDS TO BE COMPLETED */
    while (!QueueIsEmpty()) {
        printf("%d\n", QueueDequeue());
    }

    return 0;
}