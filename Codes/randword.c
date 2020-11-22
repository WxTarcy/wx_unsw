#include <stdlib.h>
#include <stdio.h>



int word(int length, int seed){
    char words[27]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
           'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};
    char w[length];
    for (int i = 0; i < length; ++i) {
        w[i]=words[rand()%25];
    }
    printf("%s",w);
    return 0;
}

int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    word(a,b);
    return 0;

}