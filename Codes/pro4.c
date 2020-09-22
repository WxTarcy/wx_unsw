//
// Created by 武轩 on 21/9/20.
//
#include <stdio.h>

typedef struct {
    int  day, moth,year;
}days;

typedef struct {
    int  hour,mins;
}times;


typedef struct {
    int Transaction_number, journey_number;
    char mode;
    float fare, discount;
    char from[32], to[32];
    char fareapplied[12];
    char week[4];
    days day;
    times time;
}opal;
