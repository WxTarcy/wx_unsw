//
// Created by 武轩 on 6/10/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node {
    int value;
    struct Node *next;
} *LinkedNode;


typedef struct List {
    LinkedNode first;
    LinkedNode last;
    int allnumber;
}*LinkedList;

LinkedNode CreatedNode(int v){
    LinkedNode node = malloc(sizeof(struct Node));
    node->value = v;
    node->next = NULL;
    return node;
}

LinkedList CreatedList(){
    LinkedList LL = malloc(sizeof(struct List));
    LL->first = NULL;
    LL->last = NULL;
    LL->allnumber = 0;
    return LL;
}

void joinLL(LinkedList LL, int data) {
    assert(LL != NULL);
    LinkedNode new = CreatedNode(data);
    if (LL->first == NULL) {
        LL->first = new;
        LL->last = new;
        LL->allnumber++;
    } else {
        LL->last->next = new;
        LL->last = new;
        LL->allnumber++;
    }
}

void freeLL(LinkedList ll) {
    assert(ll != NULL);
    LinkedNode p = ll->first;
    while(p!=NULL) {
        LinkedNode next = p->next;
        free(p);
        p = next;
    }
    free(ll);
}


void showLL(LinkedList ll) {
    assert(ll != NULL);
    LinkedNode p = ll->first;
    printf("Done. ");
    if (p != NULL) {
        printf("List is ");
        if(ll->allnumber==1){
            printf("%d",p->value);
        } else{
            for (LinkedNode i = p; i->next != NULL; i = i->next) {
                printf("%d-->", i->value);
                p = i;
            }
            printf("%d", p->next->value);
        }
    }
}



int  main(){
    LinkedList LL=CreatedList();
    int a;
    int b;
    while (1){
        printf("Enter an integer: ");
        b=scanf("%d",&a);
        if(b==1){
            joinLL( LL,a);
        }else{
            break;
        }
    }
    showLL(LL);
    freeLL(LL);
    return 0;

}

