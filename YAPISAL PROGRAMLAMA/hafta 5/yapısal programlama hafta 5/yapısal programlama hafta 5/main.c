
#include <stdio.h>
#include <stdlib.h>
void fillArray(int *dizi,int n);
void printArray(int *dizi, int n);
int main() {
    int *dizi;
    int *tmp;
    int N;
    printf("İlk dizi boyutu giriniz: \n");
    scanf("%d", &N);
   dizi=(int *)malloc(N*sizeof(int));
    fillArray(dizi, N);
    printArray(dizi, N);
    do {
        printf("Yeni dizi boyutu giriniz: \n");
        scanf("%d", &N);
        tmp=realloc(dizi, N*sizeof(int));
        if (N==0) {
            printf("Dizi serbest birakildi.\n");
            return 0;
        }
        if (tmp!=NULL) {
            dizi=tmp;
            printf("%p\n",dizi);
            fillArray(dizi, N);
            printArray(dizi, N);
        }
        else{
            printf("Hata!\n");
            return -1;
        }
    } while (N>=0);
    free(dizi);
    
    
    
    
    return 0;
}
void fillArray(int *dizi,int n){
    int i;
    for (i=0; i<n; i++) {
        dizi[i]=i;
    }
}

void printArray(int *dizi, int n){
    int i;
    for (i=0; i<n; i++) {
        printf("%3d",dizi[i]);
    }
    printf("\n****************************\n");
    
}

