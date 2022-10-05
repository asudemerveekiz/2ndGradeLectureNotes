//
//  main.c
//  yapısal_uygulama_1_soru_2
//
//  Created by Asude Ekiz on 1.11.2021.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
int main() {
    setlocale(LC_ALL, "turkish");
    char main_text[500]="Ali ata bak, dön git bir daha bak";
    char searched[500];
    int main_text_length, searched_text_length,i,j,count=0;
    
    printf("Aramak istediğiniz kelimeyi giriniz: \n");
    gets(searched);
    i=0;
    while (main_text[i]!='\0') {
        main_text[i]=tolower(main_text[i]); //büyük harfi küçük harfe dönüştüren fonksiyon (ctype.h'ta)
        i++;
    }
    main_text_length=i;
    //printf("Main text küçük harflerle: %s\n",main_text);
    
    i=0;
    while (searched[i]!='\0') {
        searched[i]=tolower(searched[i]); //büyük harfi küçük harfe dönüştüren fonksiyon (ctype.h'ta)
        i++;
    }
    searched_text_length=i;
  //  printf("Searched text küçük harflerle: %s\n",searched);
    
    //printf("Main text boyut: %d\n", main_text_length);
    //printf("Searched text boyut: %d\n", searched_text_length);
    
    for (i=0; i<=main_text_length-searched_text_length; i++) {
        j=0;
        while ((j<searched_text_length)&&(searched[j]==main_text[i+j])) {
            j++;
        }
        if (j==searched_text_length) {
            printf("Aradığınız kelime %d ile %d arasında bulundu.\n",i+1,i+j);
            count++;
        }
    }
    if (count==0) {
        printf("Aradığınız kelime bulunamadı.\n");
    }
    else{
        printf("Aradığınız kelime %d adet bulundu.\n",count);
        
    }
    
    
    return 0;
}
