// Integer Stack ADO tester ... COMP9024 20T2
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

//int main(void) {
//    int i, n;
//    char str[BUFSIZ];
//
//    StackInit();
//
//    printf("Enter a positive number: ");
//    scanf("%s", str);
//    if ((n = atoi(str)) > 0) {    // convert to int and test if positive
//        for (i = 0; i < n; i++) {
//            printf("Enter a number: ");
//            scanf("%s", str);
//            StackPush(atoi(str));
//        }
//    }
//    while(!StackIsEmpty()){
//        printf("%d",StackPop());
//        printf("\n");
//    }
//
//    /* NEEDS TO BE COMPLETED */
//
//    return 0;
//}

int main(void ){
    char value[10];
    StackInit();
    printf("Enter a number: ");
    scanf("%s",value);
    int v=atoi(value);
    while (v>0){
        StackPush(v%2);
        v=v/2;
    }
    while (!StackIsEmpty()){
        printf("%d",StackPop());
    }
    return 0;
}