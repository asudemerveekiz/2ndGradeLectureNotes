//
//  main.c
//  pointer malloc karisik
//
//  Created by Asude Ekiz on 9.11.2021.
//

#include <stdio.h>
#include <stdlib.h>


int *makeArray(size_t size, int val);

int main(int argc, const char * argv[]) {

   int *p= makeArray(5, 20);// burdaki 5 dizi boyutu, yani 5 byte değil. 5 tane içinde bir int olan kutu gibi düşün yani bir kutuda 4 byte var. ve onları 20 ile doldursun istedik
    //dışarıdan da alabilirdik
    
    for (int i=0; i<5; i++) {
        printf("%d ",p[i]);
    }
    printf("\n");
    
    //burda da size ile value'yi disardan alalım;//bu kısmı ben ekledim kurstakine ek
    int size;
    int val;
    
    printf("Lutfen dizinin boyutunu giriniz: \n");
    scanf("%d",&size);
    printf("Dizi hangi degerle doldurulacak?\n");
    scanf("%d",&val);
    int*p2=makeArray(size, val);
    for (int i=0; i<size; i++) {
        printf("%d ",p2[i]);
    }
 
   
    return 0;
}


int *makeArray(size_t size, int val){
   int *ptr=(int*) malloc(size*sizeof(int));
    if (ptr!=NULL) {
    for (int i=0; i<size; i++) {
        ptr[i]=val;
        }
    }
    return ptr;
    }
