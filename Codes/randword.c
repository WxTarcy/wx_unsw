
#include <stdio.h>
#include <stdlib.h>
#define BEGIN  97  // ASCII of 'a'

int main(int argc, char *argv[]) {
    int length = atoi(argv[1]);
    int seed = atoi(argv[2]);
    srand(seed);
    for (int i = 0; i < length; i++){
        printf("%c", (rand() % 26 + BEGIN));
    }
    return 0;
}