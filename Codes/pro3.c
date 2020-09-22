//
// Created by 武轩 on 19/9/20.
//

#include <stdio.h>

int main(void) {
    int a, b;
    for (a = 10000; a * 4 < 100000; a++) {
        b = a * 4;
        if (a / 10000 == b % 10) {
            if ((a / 1000) % 10 == (b % 100) / 10) {
                if ((a / 100) % 10 == (b % 1000) / 100) {
                    if (a % 10 == b / 10000) {
                        if ((b / 1000) % 10 == (a % 100) / 10) {
                            printf("%d", a);
                            printf("\n");
                        }
                    }
                }
            }

        }
    }
}
