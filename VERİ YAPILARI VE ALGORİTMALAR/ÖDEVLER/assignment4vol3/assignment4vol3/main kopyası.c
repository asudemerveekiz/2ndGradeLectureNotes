//
//  main.c
//  assignment4vol3
//
//  Created by Asude Ekiz on 9.05.2022.
//

#include <stdio.h>
#include <string.h>


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

int main(int argc, const char * argv[]) {
    EDGELIST spanlist;
    addFile(spanlist);
    printResult(spanlist);
        

    return 0;
}

EDGELIST addFile(EDGELIST spanlist){
    FILE *p = NULL;
    int i = 0;
    char buffer[255];
    if((p = fopen("/Users/asude/Desktop/DÖNEM 2/VERİ YAPILARI VE ALGORİTMALAR/veriyapilari ödev4/Sample_MST.txt", "r")) != NULL){
        while (fgets(buffer, 255, p)!=NULL) {
            sscanf(buffer,"%d %d %d" ,&spanlist.data[i].w,&spanlist.data[i].u,&spanlist.data[i].v);
            i++;
        }
        spanlist.n=i;
        return spanlist;
        
       
    }
    else{
        printf("Dosya acilamadi:\n");
        return spanlist;
    }
  
}
void printResult(EDGELIST spanlist){
    int i, cost=0;
    for (i=0;i< spanlist.n; i++) {
        printf("%d %d %d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
      
    }
   
}
