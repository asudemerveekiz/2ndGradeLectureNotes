//
//  main.c
//  yapısal_uygulama_2_soru_2
//
//  Created by Asude Ekiz on 13.11.2021.
//


#include <stdio.h>
#include <stdlib.h>
//üç adet zar beraber atılıyor ve üst yüze gelen rakamlar toplanıyor. üç zarın olası her bir toplam sonucu
//birinci kolonda, lasılığı da ikinci kolonda olacak şekilde bir matris dinamik bellek allokasyonu ile
//tanımlanıyor.

#define P (float)1/(6*6*6)

int main() {
    
    float **deger;
    int toplam;
    
    int i,j,k;
    deger=(float**)calloc(16,sizeof(float*));
    if (deger==NULL) {
        printf("Bellek yetersiz!!\n");
        return -1;
    }
    for (i=0; i<16; i++) {
        deger[i]=(float*)calloc(2,sizeof(float));
        if (deger[i]==NULL) {
            printf("Bellek yetersiz!\n");
            return -1;
        }
    }
    
    for (i=1; i<=6; i++) {
        for (j=1; j<=6; j++) {
            for (k=1; k<=6; k++) {
                toplam=i+j+k;
                deger[toplam-3][0]=toplam;
                //toplam en az 3 olabilir ve 0. indexte olur. toplam en fazla 18 olabilir o da 15. indexte olur. yani toplam değerinin 3 eksiği bize matrisin kaçıncı satırında olduğumuzu gösteriyor.
                
                deger[toplam-3][1]+=P;

            }
        }
    }
    
    for (i=0; i<16; i++) {
        printf("%.f\t%.8f\n",deger[i][0],deger[i][1]);
    }
    
    for (i=0; i<16; i++) {
        free(deger[i]);
    }
    free(deger);
    return 0;
}
