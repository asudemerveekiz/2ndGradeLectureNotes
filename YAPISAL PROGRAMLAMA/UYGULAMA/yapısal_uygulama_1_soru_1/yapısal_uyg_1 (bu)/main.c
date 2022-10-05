//
//  main.c
//  yapısal_uyg_1 (bu)
//
//  Created by Asude Ekiz on 1.11.2021.
//

#include <locale.h>
#include <stdio.h>
#include "calculations.h"
#include "menu.h"

int main() {
    setlocale(LC_ALL, "turkish"); //Türkçe karakterler bu sayede sorunsuz kullanılabilecek
    
    int selection, run=1,x,y,result;
    while (run) {
        MENU;
        scanf("%d",&selection);
        
        switch (selection) {
            case 1://Toplama
                printf("input 1: \n");
                scanf("%d",&x);
                printf("input 2: \n");
                scanf("%d",&y);
                ;
                printf("%d + %d = %d\n",x,y,SUM(x, y));
                break;
            case 2://Çıkarma
                printf("input 1: \n");
                scanf("%d",&x);
                printf("input 2: \n");
                scanf("%d",&y);
              
                printf("%d - %d = %d\n",x,y,DIFFERENCE(x, y));
                break;
            case 3://Çarpma
                printf("input 1: \n");
                scanf("%d",&x);
                printf("input 2: \n");
                scanf("%d",&y);
              
                printf("%d * %d = %d\n",x,y,PRODUCT(x, y));
                break;
            case 4://Bölme
                printf("input 1: \n");
                scanf("%d",&x);
                printf("input 2: \n");
                scanf("%d",&y);
                
                printf("%d / %d = %d\n",x,y,QUOTIENT(x, y));
                break;
            case 5://Faktöriyel
                printf("n!, n değerini giriniz: \n");
                scanf("%d",&x);
                result=x;
                y=x;
                while (x>1) {
                    result=result* --x;
                }
                printf("%d!= ",y);
                for (y; y>0; y--) {
                    if (y==1) {
                        printf("%d = %d\n",y,result);
                    }
                    else{
                        printf("%d * ",y);
                    }
                        
                }
                break;
            case 6://Çıkış
                run=0;
                break;
            default://tanımlı olan caseler dışında bir şeyler girilirse isteyeceğimiz şey
                printf("Geçerli bir giriş yapmadınız, lütfen tekrar deneyin.\n");
                break;
                
        }
    }
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

