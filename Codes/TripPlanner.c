/*  the Complexity of showLines is  O(mk)
 *  the Complexity of dijkstraSSSP and dijkstraSSSPShowLine is same which is O(mklogmk)
 *  the Complexity of Graph is O(mmkk)
 * */


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
//final printf time and bus station name
//Complexity O(K)
void showLines(int a[],int b,Schedule *schedules,int BusNo){
    int currentNo=0;
    currentNo=BusNo;
    if(a[b]!=-1){
        BusNo=schedules[b]->busIndex;
        showLines(a,a[b],schedules,BusNo);
    }
    if (currentNo!=BusNo){
        printf("%s %s",schedules[b]->time,schedules[b]->name);
        printf("Change at %s\n",schedules[b]->name);
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

void dijkstraSSSPShowLine(Graph g, int source,Schedule *schedules,Vertex end,int busNO) {
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
    showLines(pred,end,schedules,busNO);

}







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
    printf("Enter the number of busses: ");
    if (scanf("%d", &num_buses) != 1) {
        return 0;
    }

    Schedule *schedules = NULL;
    int index = 0;
    int totalStops = 0;
    for (int busIndex = 0; busIndex < num_buses; busIndex++) {
        printf("Enter the number of stops: ");
        scanf("%d", &num_stops);
        totalStops +=num_stops;
        schedules = realloc(schedules, sizeof(Schedule) * totalStops);
        for(int busStopIndex =0 ;busStopIndex <num_stops;busStopIndex++) {
            schedules[index] = createSchedule(busIndex);
            index++;
        }
    }
    //create graph
    Graph lines=newGraph(totalStops);
    for (int i = 0; i < totalStops; ++i) {//create graph in same bus line
        if (i!=totalStops-1&&schedules[i]->busIndex==schedules[i+1]->busIndex){
            Edge line;
            line.v=i;
            line.w=i+1;
            line.weight=schedules[i+1]->intTime-schedules[i]->intTime;
            insertEdge(lines,line);
        }
        for (int j = 0; j < totalStops; ++j) {//create graph in different bus line
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
            printf("Thank you for using TripPlanner.\n");
            break;
        }
        printf("To: ");
        scanf("%s",To);
        printf("Arrive by: ");
        scanf("%s",arrive_time);
        int hour=atoi(arrive_time)/100;
        int intFinalTime=hour*60+atoi(arrive_time+2);
        int count=0;//Record the number of start stop that meet the requirements
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
        int c=0;//Record the number of end stop that meet the requirements
        for (int j = 0; j < totalStops ;j++) {
            if (strcmp(To,schedules[j]->name)==0 && schedules[j]->intTime<=intFinalTime){
                ToNum[c]=j;
                c++;
            } else{
                ToNum[c]=-1;
                c++;
            }
        }
        int useTime=VERY_HIGH_VALUE,finalFrom=0,finalTo=0;
        for (int i = 0; i < totalStops; ++i) {//Use dijkstra algorithm to find the most suitable route
            for (int j = 0; j < totalStops; ++j) {
                if (FromNum[i]!=-1 && ToNum[j]!=-1){
                    if (useTime>dijkstraSSSP(lines,FromNum[i],ToNum[j])){
                        useTime=dijkstraSSSP(lines,FromNum[i],ToNum[j]);
                        finalFrom=FromNum[i];
                        finalTo=ToNum[j];
                    }

                }
            }
        }
        //printf part
        if (useTime==VERY_HIGH_VALUE){
            printf("No connection found.\n");
        } else{
            dijkstraSSSPShowLine(lines,finalFrom,schedules,finalTo,schedules[finalTo]->busIndex);
        }


    }


    //free memory
    freeGraph(lines);
    for(index = 0; index < totalStops;index ++) {
        free(schedules[index]->name);
        free(schedules[index]->time);
        free(schedules[index]);
    }
    free(schedules);
}



