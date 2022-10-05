//
//  main.c
//  Lab1-20011623
//
//  Created by Asude Ekiz on 1.11.2021.
//

#include <stdio.h>
#include "macros.h"
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    
    int values[POPULATION];
    int costs[POPULATION];
    int best_cost[ITERATION];
    int i,j,k,temp,best_all;
    
    printf("Population size:%d \n",POPULATION);
    printf("Iteration number:%d \n", ITERATION);
    printf("Iterations start\n");
    
    
    for (k=1; k<=ITERATION; k++) {
        printf("\n");
        printf("Iteration %d new population:\n",k);
        for (i=0; i<POPULATION; i++) {
            values[i]=5+rand()%20;
            printf("%d ",values[i]);
            
        }
        printf("\n");
        for (i=0; i<POPULATION; i++) {
            SQUARING(values[i], costs[i]);
           
            
        }
        //siralama kismi
        for (i=1; i<POPULATION; i++) {
            j=i;
            temp=costs[i];
            while ((j>0) && (temp<costs[j-1]) ) {
                costs[j]=costs[j-1];
                j=j-1;
                
            }
            costs[j]=temp;
        }
        
        best_cost[k]=costs[0];
        printf("\nBest Cost in Iteration %d: %d\n",k, best_cost[k]);
    }
    
    //tum costlar icinde siralama
    //siralama kismi
    for (i=1; i<ITERATION; i++) {
        j=i;
        temp=best_cost[i];
        while ((j>0) && (temp<best_cost[j-1]) ) {
            best_cost[j]=best_cost[j-1];
            j=j-1;
            
        }
        best_cost[j]=temp;
    }
   
    
    best_all=best_cost[0];
    
    printf("\nBest cost in all values: %d\n",best_all);
   
    
   
    return 0;
}
