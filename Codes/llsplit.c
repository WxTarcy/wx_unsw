
//
// Created by 武轩 on 6/10/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node *LinkedNode;

struct Node {
    int value;
    LinkedNode next;
};

typedef struct List *LinkedList;

struct List {
    LinkedNode first;
    LinkedNode last;
    int allnumber;
};

LinkedNode CreatedNode(int v){
    LinkedNode new = malloc(sizeof(struct Node));
    new->value = v;
    new->next = NULL;
    return new;
}

LinkedList CreatedList(){
    LinkedList new = malloc(sizeof(struct List));
    new->first = NULL;
    new->last = NULL;
    new->allnumber = 0;
    return new;
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
    LinkedNode temp = ll->first;
    while(temp!=NULL) {
        LinkedNode next = temp->next;
        free(temp);
        temp = next;
    }
    free(ll);
}


void showLL(LinkedList ll) {
    assert(ll != NULL);
    LinkedNode p = ll->first;
    printf("Done. ");
    if (p != NULL) {
        printf("List is ");

        for (LinkedNode i = p; i->next != NULL; i = i->next) {
            printf("%d-->", i->value);
            p = i;
        }
        printf("%d", p->next->value);
    }
}

void showhalf(LinkedList ll){
    assert(ll != NULL);
    LinkedNode p = ll->first;
    if (p != NULL) {
        printf("\n");
        printf("First part is ");
        int c=0;
        if (ll->allnumber%2==0){
            for (LinkedNode i = p; c<ll->allnumber/2-1; i = i->next) {
                printf("%d-->", i->value);
                p = i;
                c++;
            }
            printf("%d",p->next->value);
            printf("\n");
            printf("Second part is ");
            for(LinkedNode y = p->next->next; y->next != NULL; y = y->next) {
                printf("%d-->", y->value);
                p = y;
            }
            printf("%d", p->next->value);
        } else{
            for (LinkedNode i = p; c<ll->allnumber/2; i = i->next) {
                printf("%d-->", i->value);
                p = i;
                c++;
            }
            printf("%d",p->next->value);
            printf("\n");
            printf("Second part is ");
            for(LinkedNode y = p->next->next; y->next != NULL; y = y->next) {
                printf("%d-->", y->value);
                p = y;
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
    showhalf(LL);
    freeLL(LL);
    return 0;

}

