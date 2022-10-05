//
//  main.c
//  kruskal
//
//  Created by Asude Ekiz on 7.05.2022.
//

#include <stdio.h>
#define MAX 100

typedef struct {
    int u,v,w;
}EDGE;

typedef struct{
    EDGE data[MAX];
    int n;
} EDGELIST;

int G[MAX][MAX],n;
EDGELIST elist;
EDGELIST spanlist;
void kruskal();
int find(int *,int);
void print();
void unionn(int *,int,int);
void selectionSort(EDGELIST elist, int n);
void swap(EDGE *xp, EDGE *yp);
void sort(EDGELIST elist);






int main(int argc, const char * argv[]) {
    int i,j,totalCost,numberOfVertices;
    printf("Enter the number of vertices:");
    scanf("%d",&numberOfVertices);
    printf("Enter the adjancecy matrix:");
    for (i=0; i<numberOfVertices; i++) {
        for (j=0; j<numberOfVertices; j++) {
            scanf("%d",&G[i][j]);
        }
    }
    kruskal();
    print();
    return 0;
}

void kruskal(int numberOfVertices){
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;//kumede henuz 0 eleman var
    for (i=1; numberOfVertices; i++) {
        for (j=0; j<i; j++) {
            if (G[i][j]!=0) {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }
    }
    sort(elist);
    
    for (i=0; i<n; i++) {
        belongs[i]=i;
    }
    
    spanlist.n=0;
    i=0;
    while ((i<elist.n)&&(spanlist.n<numberOfVertices)) {
        cno1=find(belongs, elist.data[i].u);
        cno2=find(belongs, elist.data[i].v);
        if (cno1!=cno2) {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n++;
            unionn(belongs,cno1,cno2);
        }
        i++;
    }
}

void unionn(int belongs[],int c1,int c2){
    int i;
    for (i=0; i<n; i++) {
        if (belongs[i]==c2) {
            belongs[i]=c1;
        }
    }
    
}
int find(int belongs[],int vertexno){
    return (belongs[vertexno]);
}

void sort(EDGELIST elist){
    selectionSort(elist, elist.n);
}

void print(){
    int i, cost=0;
    for (i=0; spanlist.n; i++) {
        printf("%d %d %d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
        cost+=spanlist.data[i].w;
        
    }
    printf("Cost of MST: %d\n",cost);
}
void swap(EDGE *xp, EDGE *yp)
{
    EDGE temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(EDGELIST elist, int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (elist.data[j].w < elist.data[min_idx].w)
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&elist.data[min_idx], &elist.data[i]);
    }
}
  

