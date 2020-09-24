
#include "IntQueue.h"
#include <assert.h>

typedef struct {
    int item[MAXITEMS];
    int  top;
} queueRep;                   // defines the Data Structure

static queueRep  queueObject;  // defines the Data Object

void QueueInit() {            // set up empty stack
    queueObject.top = -1;
}

int QueueIsEmpty() {          // check whether stack is empty
    return (queueObject.top <0);
}

void QueueEnqueue(int ch) {     // insert char on top of stack
    assert(queueObject.top< MAXITEMS-1);
    queueObject.top++;
    int i = queueObject.top;
    queueObject.item[i] = ch;
}

int QueueDequeue() {             // remove char from top of stack
    assert(queueObject.top > -1);
    int ch = queueObject.item[0];
    for(int y =0;y<=queueObject.top;y++){
        queueObject.item[y]=queueObject.item[y+1];
    }
    queueObject.top--;
    return ch;
}
