#include "WGraph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


void insertionSort(float array[], int n,int array_two[]) {
    int i;
    for (i = 1; i < n; i++) {
        float element = array[i];// for this element ...
        int num=array_two[i];
        int j = i-1;
        while (j >= 0 && array[j] < element) {  // ... work down the ordered list
            array[j+1] = array[j];// ... moving elements up
            array_two[j+1]=array_two[j];
            j--;
        }
        array_two[j+1]=num;
        array[j+1] = element;                   // and insert in correct position
    }
}

int main(){
    //make a graph
    int a;
    int b;
    Graph g;
    printf("Enter the number of vertices: ");
    b=scanf("%d",&a);
    if(b==1){
        g=newGraph(a);
    }else{
        printf("Done.\n");
    }

    if(b==1){
        //Declare variables
        int newvers_one;
        int test_one;
        int newvers_two;
        int test_two;
        Edge e;
        float count_out[a];
        float count_in[a];
        int fin[a];
        for(int q=0;q<a;q++){
            count_in[q]=0;
            count_out[q]=0;
            fin[q]=q;
        }

        for (int c=1;c<=a*a;c++) {
            printf("Enter an edge (from): ");
            test_one = scanf("%d", &newvers_one);
            if (test_one == 0) {
                printf("Done.\n");
                break;
            } else {
                printf("Enter an edge (to): ");
                test_two = scanf("%d", &newvers_two);
                if (test_two == 1) {
                    count_out[newvers_one]++;
                    count_in[newvers_two]++;
                    e.v=newvers_one;
                    e.w=newvers_two;
                    e.weight=1;
                    insertEdge(g,e);
                } else {
                    printf("Done.\n");
                    break;
                }
            }
        }
        //show the ranking
        printf("Popularity ranking:\n");
        float result[a];
        for(int i=0;i<a;i++){
            if (count_out[i]<0.9){
                result[i]=2*count_in[i];
            } else{
                result[i]=count_in[i]/count_out[i];
            }
        }
        insertionSort(result,a,fin);
        for (int i = 0; i < a; i++){
            printf("%d %.1f\n",fin[i], result[i]);
        }
        freeGraph(g);
    }
    return 0;
};

