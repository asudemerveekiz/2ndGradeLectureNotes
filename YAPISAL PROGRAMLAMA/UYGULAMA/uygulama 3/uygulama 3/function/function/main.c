//
//  main.c
//  function
//
//  Created by Asude Ekiz on 12.12.2021.
//

#include <stdio.h>


void print(){
    printf("Hello world!");
}
void hello_world(void(*fonksiyon)()){
    fonksiyon();
}
int main(int argc, const char * argv[]) {
 
    hello_world(print);
    return 0;
}
