//
//  main.c
//  yapısal vize 1 soru cozumleri
//
//  Created by Asude Ekiz on 10.12.2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //char *x[5]={"ElHarizmi780","CharlesBubbage1791","AdaLovelace1815","AlanTuring1912", "Dennis Ritchie1941"};
    //char *y[]={x[0],x[3]}; char *p=y[0];
    //printf("%p \n", (p+2));
    //printf("%p \n",y[1]);
    //printf("%c \n",*(*(x+3)+2));
    //printf("%c \n", *(*(y+1)[4]);
    //printf("%c \n",*(++y[1]));
    //printf("%c \n", x[2][0]-x[1][7]+x[0][0]);
    
    int i=1;
    int *p=&i;
    int *q=p;
    *q=5;
 
    
    
    printf("%d", *p);
    
    return 0;
}
