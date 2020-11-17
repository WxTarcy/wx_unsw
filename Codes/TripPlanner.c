
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

#define  STOP_NAME 32
#define  TIME 5

#define VERY_HIGH_VALUE 999999


typedef struct schedule {
    char *name;
    char *time;
    int busIndex;
    int intTime;
    //int totalNum;
} * Schedule;

Schedule createSchedule(int busIndex){
    Schedule newSchedule = malloc(sizeof(struct schedule));
    newSchedule->time = malloc(sizeof(char) * TIME);
    scanf("%s", newSchedule->time);
    newSchedule->name = malloc(sizeof(char) * STOP_NAME);
    scanf("%s", newSchedule->name);
    newSchedule->busIndex = busIndex;
    int hour=atoi(newSchedule->time)/100;
    newSchedule->intTime=hour*60+atoi(newSchedule->time+2);
    return newSchedule;
}

void print_track(int a[],int b,Schedule *schedules,int BusNo){
    if(a[b]!=-1){
        BusNo=schedules[b]->busIndex;
        print_track(a,a[b],schedules,BusNo);
    }
    if (BusNo!=schedules[b]->busIndex){
        printf("\n%s %s",schedules[b]->time,schedules[b]->name);
        printf(" Change at %s",schedules[b]->name);
    } else{
        printf("%s %s\n",schedules[b]->time,schedules[b]->name);
    }
}


int dijkstraSSSP(Graph g, int source,Vertex end) {
    int  dist[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s;
    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        vSet[s] = true;
    }
    dist[source] = 0;

    while (PQueueIsEmpty() == false) {
        // find  minimum distance to source point
        int leave_point = leavePQueue(dist);
        for (int t = 0; t < nV; t++) {
            int weight = adjacent(g, leave_point, t);
            if (weight > 0&& vSet[t] && dist[leave_point] + weight < dist[t]) {
                dist[t] = dist[leave_point] + weight;
            }
        }

        vSet[leave_point] = false;
    }
    return dist[end];
}


void dijkstraSSSPs(Graph g, int source,Schedule *schedules,Vertex end,int busNO) {
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
            if (weight > 0&& vSet[t] && dist[leave_point] + weight < dist[t]) {
                dist[t] = dist[leave_point] + weight;
                pred[t] = leave_point;
            }
        }

        vSet[leave_point] = false;
    }
    print_track(pred,end,schedules,busNO);

}
////输出结果
//    if (dist[end]<VERY_HIGH_VALUE&&time>=schedules[end]->intTime){
//        print_track(pred,end,schedules);
//    } else{
//        printf("No connection found");
//        printf("\n");
//    }








int main() {
    //first part
    int num_bus_stops = 0;
    char *name=NULL;
    printf("Enter the number of bus stops: ");
    if (scanf("%d", &num_bus_stops) != 1) {
        return 0;
    }
    for(int i=0;i<num_bus_stops;i++){
        name=malloc(sizeof(char)*STOP_NAME);
        scanf("%s",name);
    }

    //second part
    int num_buses;
    int num_stops;
    printf("Enter the number of buses: ");
    // 0    5
    // 1
    // 1    2
    if (scanf("%d", &num_buses) != 1) {
        return 0;
    }

    Schedule *schedules = NULL;
    int index = 0;
    int totalStops = 0;
    for (int busIndex = 0; busIndex < num_buses; busIndex++) {
        printf("Enter the number of stops: ");
        scanf("%d", &num_stops);
        // 总共有多少站
        totalStops +=num_stops;
        schedules = realloc(schedules, sizeof(Schedule) * totalStops);
        for(int busStopIndex =0 ;busStopIndex <num_stops;busStopIndex++) {
            schedules[index] = createSchedule(busIndex);
            index++;
        }
    }
//    for(index = 0; index < totalStops;index ++) {
//        printf("%s,%s,%d,%d\n", schedules[index]->name, schedules[index]->time, schedules[index]->busIndex,schedules[index]->intTime);
//    }
    Graph lines=newGraph(totalStops);
    for (int i = 0; i < totalStops; ++i) {
        if (i!=totalStops-1&&schedules[i]->busIndex==schedules[i+1]->busIndex){
            Edge line;
            line.v=i;
            line.w=i+1;
            line.weight=schedules[i+1]->intTime-schedules[i]->intTime;
            insertEdge(lines,line);
        }
        for (int j = 0; j < totalStops; ++j) {
            if (strcmp(schedules[i]->name,schedules[j]->name)==0&&schedules[i]->busIndex!=schedules[j]->busIndex){
                if (schedules[i]->intTime<schedules[j]->intTime){
                    Edge line;
                    line.v=i;
                    line.w=j;
                    line.weight=abs(schedules[j]->intTime-schedules[i]->intTime);
                    insertEdge(lines,line);
                }
            }
        }
    }
    char From[STOP_NAME],To[STOP_NAME],arrive_time[TIME];
    while (1){
        printf("From: ");
        scanf("%s",From);
        if(strcmp(From,"done")==0){
            printf("Thank you for using TripPlanner.");
            break;
        }
        printf("To: ");
        scanf("%s",To);
        printf("Arrive by: ");
        scanf("%s",arrive_time);
        int hour=atoi(arrive_time)/100;
        int intFinalTime=hour*60+atoi(arrive_time+2);
        int count=0;
        int FromNum[totalStops];
        for (int i = 0; i < totalStops; ++i) {
            if (strcmp(From,schedules[i]->name)==0){
                FromNum[count]=i;
                count++;
            } else{
                FromNum[count]=-1;
                count++;
            }
        }
        int ToNum[totalStops];
        int c=0;
        for (int j = 0; j < totalStops ;j++) {
            if (strcmp(To,schedules[j]->name)==0 && schedules[j]->intTime<=intFinalTime){
                ToNum[c]=j;
                c++;
            } else{
                ToNum[c]=-1;
                c++;
            }
        }
        int useTime=999999,finalfrom=0,finalto=0;
        for (int i = 0; i < totalStops; ++i) {
            for (int j = 0; j < totalStops; ++j) {
                if (FromNum[i]!=-1 && ToNum[j]!=-1){
                    if (useTime>dijkstraSSSP(lines,FromNum[i],ToNum[j])){
                        useTime=dijkstraSSSP(lines,FromNum[i],ToNum[j]);
                        finalfrom=FromNum[i];
                        finalto=ToNum[j];
                    }

                }
            }
        }
        if (useTime==999999){
            printf("No connection found.\n");
        } else{
            dijkstraSSSPs(lines,finalfrom,schedules,finalto,schedules[finalto]->busIndex);
        }


    }




    freeGraph(lines);
    for(index = 0; index < totalStops;index ++) {
        free(schedules[index]->name);
        free(schedules[index]->time);
        free(schedules[index]);
    }
    free(schedules);
}



//1200
//c
//1245
//b
//1300
//a