//
//  main.c
//  prim algorithm
//
//  Created by Asude Ekiz on 14.05.2022.
//

#include <stdio.h>
#define MAX 100
#define infinity 9999
int n;
int main(int argc, const char * argv[]) {
    
    return 0;
}
int prim(){
    int G[MAX][MAX];
    int cost[MAX][MAX];
    int spanning[MAX][MAX];
    int u,v = 0,min_distance,distance[MAX],from[MAX];
    int visited[MAX],numberOfEdges,min_cost,i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (G[i][j]==0) {
                cost[i][j]=infinity;
                }
            else{
                cost[i][j]=G[i][j];
            }
            spanning[i][j]=0;
        }
        
    }
    distance[0]=0;
    visited[0]=1;
    
    for (i=1; i<n; i++) {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    min_cost=0;
    numberOfEdges=n-1;
    while (numberOfEdges>0) {
        min_distance=infinity;
        for (i=1; i<n; i++) {
            if ((visited[i]==0)&&(distance[i]<min_distance)) {
                v=i;
                min_distance=distance[i];
            }
            u=from[v];
            spanning[u][v]=distance[v];
            spanning[v][u]=distance[v];
            numberOfEdges--;
            visited[v]=1;
            
            for (i=1; i<n; i++) {
                if ((visited[i]==0)&&(cost[i][v]<distance[i])) {
                    distance[i]=cost[i][v];
                    from[i]=v;
                }
            }
            min_cost+=cost[u][v];
        }
    }
    return min_cost;
}
