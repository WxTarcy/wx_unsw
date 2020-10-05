//
//
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <memory.h>
//
//
//int main(void) {
//    int a;
//    int b;
//    char aa[10];
//    printf("输入一个数:");
//    b=scanf("%d",&a);
//    int c=strlen(aa);
//    printf("c=%d\n",c);
//    printf("\n");
//    if(b==1){
//        printf("%d",a);
//    }
//}


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NodeT *LinkedNode;

struct NodeT {
    int value;
    LinkedNode next;
};

typedef struct ListT *LinkedList;

struct ListT {
    LinkedNode head;
    LinkedNode tail;
    int count;
};

LinkedNode makeNode(int v){
    LinkedNode new = malloc(sizeof(struct NodeT));
    new->value = v;
    new->next = NULL;
    return new;
}

LinkedList createLL (){
    LinkedList new = malloc(sizeof(struct ListT));
    new->head = NULL;
    new->tail = NULL;
    new->count = 0;
    return new;
}

void joinLL(LinkedList list, int data) {
    assert(list != NULL);

    LinkedNode newNode = makeNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        list->count++;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->count++;
    }
}


void showLL(LinkedList list) {
    assert(list != NULL);
    LinkedNode p = list->head;
    printf("Done. ");
    if (p != NULL) {
        printf("List is ");
    }
    while(p != NULL){
        if (p->next != NULL){
            printf("%d-->", p->value);
        } else {
            printf("%d", p->value);
        }
        p = p->next;
    }
}

void freeLL(LinkedList list) {
    assert(list != NULL);
    LinkedNode temp = list->head;
    while(temp!=NULL) {
        LinkedNode next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

int main() {
    LinkedList all = createLL();

    int n;
    while (1){
        printf("Enter an integer: ");
        if (scanf("%d", &n) == 1) {
            joinLL(all, n);
        } else{
            break;
        }
    }

    showLL(all);

    freeLL(all);

    return 0;
}