//
//  main.c
//  Lab3-20011623
// //
//  Created by Asude Ekiz on 13.12.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define SIZE 3
void karsilastir(char*model, char* temp);
typedef struct arac{
    char *model;
    int yil;
    int fiyat;
    int adet;
}ARAC;

int main(int argc, const char * argv[]) {
    int secim;
    int yon;

    ARAC *ARACDIZI;
    ARAC *TMP;
    ARACDIZI=(ARAC*)malloc(SIZE*sizeof(ARAC));
    //arac 1
    ARACDIZI[0].model="FiatModel1";
    ARACDIZI[0].yil=2019;
    ARACDIZI[0].fiyat=200000;
    ARACDIZI[0].adet=3;
    
    //arac 2
    ARACDIZI[1].model="Mercedes1";
    ARACDIZI[1].yil=2020;
    ARACDIZI[1].fiyat=600000;
    ARACDIZI[1].adet=10;
    //arac 3
    ARACDIZI[2].model="RenaultModel1";
    ARACDIZI[2].yil=2020;
    ARACDIZI[2].fiyat=185000;
    ARACDIZI[2].adet=5;
    
    char *model[SIZE]={ARACDIZI[0].model,ARACDIZI[1].model,ARACDIZI[2].model};
    char *temp;
   
    
    
    printf(" Arac eklemek icin 1 e \n Var olan listeyle devam etmek icin 2'ye \n Cikis icin 3'e basiniz: ");
    scanf(" %d",&secim);
    while (secim!=3) {
        
        if (secim==2) {
            printf("2 secildi\n");
            printf("Artan siralama icin 1'e, azalan siralama icin 2'ye basiniz: \n");
            scanf(" %d",&yon);
            if (yon==1) {
                karsilastir(model, temp);
            }
            else if(yon==2){
                //azalan siralama yap
            }
            
            printf(" Arac eklemek icin 1 e \n Var olan listeyle devam etmek icin 2'ye \n Cikis icin 3'e basiniz: \n");
            scanf(" %d",&secim);
        }
        else if (secim==1){
            printf("1 secildi.\n");
            TMP=realloc(ARACDIZI, (SIZE+1)*sizeof(ARAC));
            if(TMP!=NULL){
                ARACDIZI = TMP;
                printf("ARACDIZI genisletildi\n");
            }else{
                printf("Hata");
                return -1;
            }

            printf("Artan siralama icin 1'e, azalan siralama icin 2'ye basiniz: \n");
            scanf(" %d",&yon);
            
            if (yon==1) {
                karsilastir(model, temp);
            }
            else if(yon==2){
                //azalan siralama yap
            }
            
            printf(" Arac eklemek icin 1 e \n Var olan listeyle devam etmek icin 2'ye \n Cikis icin 3'e basiniz: \n");
            scanf(" %d",&secim);
        }
        
    }
    printf("Cikis yapildi:");
    
    
 
    return 0;
}

void karsilastir(char*model, char* temp){
    int i,j;
    for (i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
           if (strcmp(model[j - 1], model[j]) > 0) {
              strcpy(temp, model[j - 1]);
              strcpy(model[j - 1], model[j]);
              strcpy(model[j], temp);
           }
        }
     }
   
     printf("\nSıralanmış hali : ");
     for (i = 0; i < 5; i++)
        printf("\n%s", model[i]);
  }



