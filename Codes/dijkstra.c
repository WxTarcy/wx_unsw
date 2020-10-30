// Starting code for Dijkstra's algorithm ... COMP9024 20T3

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 999999



void print_track(int a[],int b,int c){
    if(a[b]!=-1){
        print_track(a,a[b],c);
    }
    if (b==c){
        printf("%d",b);
    } else{
        printf("%d-",b);
    }
}
void dijkstraSSSP(Graph g, Vertex source) {
    int  dist[MAX_NODES];
    int  pred[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s;

    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;


    while (PQueueIsEmpty() == false) {
        // find  minimum distance to source point
        int leave_point = leavePQueue(dist);
        for (int t = 0; t < nV; t++) {
            int weight = adjacent(g, leave_point, t);
            if (weight > 0 && dist[leave_point] + weight < dist[t]) {
                dist[t] = dist[leave_point] + weight;
                pred[t] = leave_point;
            }
        }
        vSet[leave_point] = false;
    }

    for(int p=0;p<nV;p++){
        if (dist[p]<VERY_HIGH_VALUE){
            printf("%d: distance = %d, shortest path: ",p,dist[p]);
            if(p==source){
                printf("%d",source);
            } else{
                print_track(pred,p,p);
            }
            printf("\n");
        } else{
            printf("%d: no path", p);
            printf("\n");
        }
    }


}

void reverseEdge(Edge *e) {
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void) {
    Edge e;
    int  n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);
        reverseEdge(&e);               // ensure to add edge in both directions
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}

