//
//  main.c
//  quiz1 histogram
//
//  Created by Asude Ekiz on 18.04.2022.
//

#include <stdio.h>
#include <stdlib.h>

void printMatris(int ** matris,int N,int M);
int main(int argc, const char * argv[]) {
    int N, M;
    int **matris;
    int **hist;
    
    
    int i,j;
    printf("N degerini giriniz:");
    scanf("%d",&N);
    printf("M degerini giriniz:");
    scanf("%d",&M);
    matris=(int**)malloc(N*sizeof(int*));
    for (i=0; i<M; i++) {
        matris[i]=(int*)malloc(M*sizeof(int));
    }
    printf("Matris degerini girin:");
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf("Matris[%d][%d]. elemani ",i,j);
            scanf("%d",&matris[i][j]);
        }
    }
    printMatris(matris,N,M);
    hist=(int**)calloc((N/3),sizeof(int**));
    hist[0]=(int*)malloc(2*sizeof(int));
    int tmp,k;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            tmp=matris[i][j];
            while (hist[k][0]!=0) {
                if (tmp==hist[k][0]) {
                    hist[k][1]++;
                }
            }
           
        }
    }
    
    return 0;
}

void printMatris(int **matris,int N,int M){
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf("%3d  ",matris[i][j]);
        }
        printf("\n");
    }
}

