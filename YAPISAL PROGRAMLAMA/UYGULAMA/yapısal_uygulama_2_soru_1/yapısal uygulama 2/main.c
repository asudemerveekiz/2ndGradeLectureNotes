//
//  main.c
//  yapısal uygulama 2
//
//  Created by Asude Ekiz on 13.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    enum palet{
        siyah=0,gri=128,beyaz=255
        };
    int N,M,i,j;
    int **resim;
    int **histogram;
    int tmp;
   
    printf("Lutfen resim boyutlarini sirasiyla satir ve sutun olarak giriniz: \n");
    scanf("%d %d", &N, &M);//scanfle alırken &N ve &M in başıdna boşluk olmazsa sıkıntı çıkarıyor bazen
 
    //matrisi dinamik bellek allokasyonu ile tanımlama
    resim= (int**)malloc(N*sizeof(int*));
    if (resim==NULL) {
        printf("Bellek yetersiz!!\n");
        return -1;
    }
    for (i=0; i<N; i++) {
        resim[i]=(int*)malloc(M* sizeof(int));
        if (resim[i]==NULL) {
            printf("Bellek yetersiz!!\n");
            return -1;
        }
    }
    //kullanicidan degerleri alma
    for (i=0; i<N; i++) {
        printf("%d. satirin elemanlarini giriniz: \n",i);
        for (j=0; j<M; j++) {
            scanf("%d", &resim[i][j]); //yine & oncesi bosluk
        }
    }
    //matrisi print etme
    printf("Resim matrisi:\n");
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf("%3d  ",resim[i][j]);
        }
        printf("\n");
    }
  
    //histogram matrisini olusturma
    histogram=(int **)calloc(3,sizeof(int*));
    if (histogram==NULL) {
        printf("Bellekte yetersiz!!\n");
        return -1;
    }
    for (i=0; i<=2; i++) {
        histogram[i]=(int*)calloc(2, sizeof(int));
        if (histogram[i]==NULL) {
            printf("Bellek yetersiz!!\n");
            return -1;
        }
        
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            tmp=resim[i][j];
            histogram[(tmp/127)][0]=tmp;//piksel değerini histogramın ilk sütununa atıyoruz
            histogram[(tmp/127)][1]++;//histogram matrisinin 2.sütun değerini 1 artırıyoruz
        }
    }
    printf("*************************\n");
    printf("Histogram matrisi:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            printf("%4d  ",histogram[i][j]);
        }
        printf("\n");
    }
    
    for (i=0; i<N; i++) { //dıstan ice doldurduk icten disa siliyoruz
        free(resim[i]);
    }
    free(resim);
    
    for (i=0; i<3; i++) {
        free(histogram[i]);
    }
    free(histogram);
    
    return 0;
}
