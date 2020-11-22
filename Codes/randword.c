
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void word(int length, int seed){
    char words[27]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
           'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};
    char w[length];
    srand(seed);
    for (int i = 0; i < length; ++i) {
        w[i]=words[rand()%26];
    }
    printf("%s",w);
}

int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    word(a,b);
    return 0;

}