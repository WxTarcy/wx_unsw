
#include <stdio.h>

int fibonacci_1(int a){
    if(a%2==0){
        return a/2;
    } else{
        return a*3+1;
    }
}

int fibonacci_2(int v){
    if(v==1){
        return 1;
    }
    else if (v==2){
        return 1;
    }
    else if(v>2 & v<10){
        int f_value=fibonacci_2(v-1)+fibonacci_2(v-2);
        return f_value;
    }
    return 0;
}
int main(void){
    int va;
    for(va=1;va<11;va++) {
        if (va == 1) {
            printf("Fib[%d]=%d",va,va);
            printf("\n");
            printf("1");
            printf("\n");
        } else if (va == 2) {
            printf("Fib[%d]=%d",va,va);
            printf("\n");
            printf("1");
            printf("\n");
        } else if (va > 2 & va <= 10) {
            int f_value = fibonacci_2(va - 1) + fibonacci_2(va - 2);
            printf("Fib[%d]=%d",va,f_value);
            printf("\n");
            while (f_value != 1) {
                printf("%d", f_value);
                f_value = fibonacci_1(f_value);
                printf("\n");
            }
            printf("1");
            printf("\n");
        }
    }
    return 0;
}