
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



#define BEGIN  97  // ASCII of 'a'

int main(int argc, char *argv[]) {
    int length = atoi(argv[1]);
    int seed = atoi(argv[2]);
    char words[27]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};
    srand(seed);
    for (int i = 0; i < length; i++){
        printf("%c",words[rand()%26]);
    }
    return 0;
}