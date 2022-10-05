//
//  main.c
//  assignment4vol3
//
//  Created by Asude Ekiz on 9.05.2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int u,v,w;
}EDGE;

typedef struct{
    EDGE data[MAX];
    int n;
} EDGELIST;

EDGELIST addFile(EDGELIST spanlist);
void printResult(EDGELIST spanlist);
void printAdjMatrix(int ** matris,int nodeNumber);
int **fillAdjMatris(EDGELIST spanlist,int **adjMatrix,int nodeNumber);
int checkForCycle(int node,int parent, int *visit,int **adjMatrix);
int **updateAdjMatris(EDGE new,int **adjMatrix,int nodeNumber);

int main(int argc, const char * argv[]) {
    int nodeNumber;
    int i,j;
    int firstV,secondV,weight;
    int result=-1;
    printf("\n--------- DATA STRUCTURES AND ALGORITHMS ASSIGNMENT 4 ------\n");
    printf("\n Asude Merve Ekiz 20011623\n\n");
           
    printf("Please enter the node number:");
    scanf("%d",&nodeNumber);
   
    EDGELIST spanlist;
    spanlist=addFile(spanlist);
    printResult(spanlist);
    
    int **adjMatrix;
    adjMatrix= (int**) calloc(nodeNumber,sizeof(int*));
    for(i=0;i<nodeNumber;i++){
        adjMatrix[i] = (int*) calloc(5,sizeof(int));
    }
    for (i=0; i<nodeNumber; i++) {
        adjMatrix[i][0]=i+1;
    }
    int *visit=(int*)calloc(nodeNumber, sizeof(int));
    
   // printAdjMatrix(adjMatrix, nodeNumber);
    fillAdjMatris(spanlist, adjMatrix, nodeNumber);
    printAdjMatrix(adjMatrix, nodeNumber);
    
    
    printf("Enter new edges first vertex:");
    scanf("%d",&firstV);
    printf("Enter new edges second vertex:");
    scanf("%d",&secondV);
    printf("Enter new edges weight:");
    scanf("%d",&weight);
    
    EDGE new;
    new.u=firstV;
    new.v=secondV;
    new.w=weight;
    updateAdjMatris(new, adjMatrix, nodeNumber);
    printAdjMatrix(adjMatrix, nodeNumber);
    
    
    
    result=checkForCycle(firstV, -1, visit, adjMatrix);
    if (result==1) {
        printf("Graph has a cycle so it must be update\n");
    }
    else if(result==0){
        printf("Graph has no cycle so it won't be update\n");
    }
    else(
         printf("Something wrong.\n"));

    return 0;
}





EDGELIST addFile(EDGELIST spanlist){
    FILE *p =fopen("Sample_MST.txt", "r");
    int i = 0;
    char buffer[255];
    if(p != NULL){
        while (fgets(buffer, 255, p)!=NULL) {
            sscanf(buffer,"%d %d %d" ,&spanlist.data[i].w,&spanlist.data[i].u,&spanlist.data[i].v);
            i++;
        }
        spanlist.n=i;
        return spanlist;
        
       
    }
    else{
        printf("File couldn't open.\n");
        return spanlist;
    }
  
}
void printResult(EDGELIST spanlist){
    int i;
    for (i=0;i< spanlist.n; i++) {
        printf("%d %d %d\n",spanlist.data[i].w,spanlist.data[i].u,spanlist.data[i].v);
      
    }
}
void printAdjMatrix(int ** matris,int nodeNumber){
    int i,j;
    printf("\nAdj Matris\n");
    for (i=0; i<nodeNumber; i++) {
        for (j=0; j<5; j++) {
            printf("%d ",matris[i][j]);
        }
        printf("\n");
    }
}

int **fillAdjMatris(EDGELIST spanlist,int **adjMatrix,int nodeNumber){
    int i=0,j=0,k=0;
    int tmp,value;
    for (i=0; i<nodeNumber-1; i++) {
        tmp=spanlist.data[i].u;
        value=spanlist.data[i].v;
        k=0;
        while ((adjMatrix[k][0]!=tmp )&&(k<nodeNumber)) {
            k++;
        }
        if (adjMatrix[k][0]==tmp) {
            j=0;
            while (adjMatrix[k][j]!=0) {
                j++;
            }
            if (adjMatrix[k][j]==0) {
                adjMatrix[k][j]=value;
            }
        }
        
    }
    for (i=0; i<nodeNumber-1; i++) {
        tmp=spanlist.data[i].v;
        value=spanlist.data[i].u;
        k=0;
        while ((adjMatrix[k][0]!=tmp )&&(k<nodeNumber)) {
            k++;
        }
        if (adjMatrix[k][0]==tmp) {
            j=0;
            while (adjMatrix[k][j]!=0) {
                j++;
            }
            if (adjMatrix[k][j]==0) {
                adjMatrix[k][j]=value;
            }
        }
        
    }

    return adjMatrix;
    
}

int checkForCycle(int node,int parent, int *visit,int **adjMatrix){
    int j,tmp;
    
    visit[node-1]=1;
    j=1;
    while (adjMatrix[node-1][j]!=0) {
        tmp=adjMatrix[node-1][j];
        if (!visit[tmp-1]) {
            if (checkForCycle(tmp,node,visit,adjMatrix)) {
                return 1;
            }
            else if(tmp!=parent){
                return 1;
            }
        }
        j++;
       }
    return 0;
}

int **updateAdjMatris(EDGE new,int **adjMatrix,int nodeNumber){
    int i,j;
    int source=new.u;
    int dest=new.v;
    i=0;
    
    while (adjMatrix[i][0]!=source) {
        i++;
    }
    if (adjMatrix[i][0]==source) {
        j=0;
        while (adjMatrix[i][j]!=0) {
            j++;
        }
        if (adjMatrix[i][j]==0) {
            adjMatrix[i][j]=dest;
        }
    }
    source=new.v;
    dest=new.u;
    i=0;
    while (adjMatrix[i][0]!=source) {
        i++;
    }
    if (adjMatrix[i][0]==source) {
        j=0;
        while (adjMatrix[i][j]!=0) {
            j++;
        }
        if (adjMatrix[i][j]==0) {
            adjMatrix[i][j]=dest;
        }
    }
    
    return adjMatrix;
    
}
