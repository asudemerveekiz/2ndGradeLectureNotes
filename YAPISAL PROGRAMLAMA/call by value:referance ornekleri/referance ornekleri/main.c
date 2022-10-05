//
//  main.c
//  referance ornekleri
//
//  Created by Asude Ekiz on 7.12.2021.
//

#include <stdio.h>
void f(int x, int *y);
void f1(int x,const int *y);;
void f2(int x,int *const y);
void f3(int x,int const *const y);
int main(int argc, const char * argv[]) {

    int x=5;
    int y=6;
    printf("%d %d\n",x,y);//5 6
    f(x,&y);
    printf("%d %d\n",x,y);//5 0
    x=y=7;
    printf("%d %d\n",x,y);//7 7
    f1(x,&y);
    printf("%d %d\n",x,y);
    f2(x,&y);
    printf("%d %d\n",x,y);//7
    
    
    
    
    return 0;
}


void f(int x, int *y){
    x=0;
    *y=0;
}
void f1(int x,const int *y){//y nin gosterdigi yerdeki degeri sabitledik
    x=0;
    y=&x;
    // *y=66; bu olmaz mesela
}
void f2(int x,int *const y){//point edilen degiskeni degistiremezsin
    x=0;
    // y=&x; yapamazsin
    *y=0;
}
void f3(int x,int const *const y){//ne pointerı ne icerigini degistirebilirsim
    x=0;
    // y=&x; yapamazsin
    //*y=0; yapamazsin
}
