//
//  main.c
//  Lab2-20011623
//
//  Created by Asude Ekiz on 15.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** allocateMatrix(int);
void getElements(int**, int);
void printMatrix(int** matrix, int N);
int** reallocateMatrix(int N);
void deallocateMatrix(int** matrix, int N);


int main() {
    int N;
    int **matrix;
    int **new_matrix;
    int i,j;
    int sum;

    printf("Please enter the N value: \n");
    scanf("%d", &N);
    srand(time(NULL));
    
    matrix=allocateMatrix(N);
    getElements(matrix, N);
    printMatrix(matrix, N);
    
    N=N+1;
    
    
    new_matrix=(int**) realloc(matrix,N*sizeof(int*));
    if(new_matrix==NULL){
        return NULL;
    }
    for(i=0;i<N;i++){
        new_matrix[i]=(int*) realloc(matrix[i],N*sizeof(int));
        if(new_matrix[i]==NULL)
            return NULL;
    }
    
    printMatrix(new_matrix, N);

    
    //yeni matrisin içini istendiği gibi doldurma
    
    for (j=0; j<N-1; i++) {
        sum=0;
        for (i=0; i<N-1; j++) {
            sum+=new_matrix[i][j];
        }
        new_matrix[N][j]=sum;
    }
 
    for (i=0; i<N-1; i++) {
        sum=0;
        for (j=0; j<N-1; j++) {
            sum+=new_matrix[i][j];
        }
        new_matrix[i][N]=sum;
    }
    printMatrix(new_matrix, N);
    
    
    deallocateMatrix(matrix, N-1);
    deallocateMatrix(new_matrix, N);
    
    
    
    
    return 0;
}


int** allocateMatrix(int N){
    int** matrix;
    int i;
    matrix=(int**) calloc(N,sizeof(int*));
    if(matrix==NULL){
        return NULL;
    }
    for(i=0;i<N;i++){
        matrix[i]=(int*) calloc(N,sizeof(int));
        if(matrix[i]==NULL)
            return NULL;
    }
    return matrix;
}

void getElements(int** matrix, int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            matrix[i][j]=rand()%100;
        }
    }
}

void printMatrix(int** matrix, int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%4d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("=====================================\n");
}


void deallocateMatrix(int** matrix, int m){
    int i;
    for(i=0;i<m;i++){
        free(matrix[i]);
    }
    free(matrix);
}
