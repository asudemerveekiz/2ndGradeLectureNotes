//
//  main.c
//  veri yapilari odev3
//
//  Created by Asude Ekiz on 3.05.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct  tree{
    char kelime[MAX];
    char dosyaAdi[MAX][MAX];
    int dosyaCounter;
    struct tree *right,*left;
}TREE;

TREE yeniNodOlustur(char *kelime, char *dosyaAdi){
    TREE *node=(TREE*)malloc(sizeof(TREE));
    strcpy(node->kelime, kelime);
    strcpy(node->dosyaAdi[0], dosyaAdi);
    node->dosyaCounter=1;
    node->left=NULL;
    node->right=NULL;
    return *node;
}

TREE dosyaEkle(char *dosyaAdi,TREE *root){
    FILE *fp=fopen(dosyaAdi, "r");
    char buffer[255];
    
}



int main(int argc, const char * argv[]) {

    return 0;
}
