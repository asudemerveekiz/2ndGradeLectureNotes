//
//  main.c
//  linked
//
//  Created by Asude Ekiz on 21.03.2022.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}NODE;

NODE* createNode(int data);
void display(NODE *head);

int main(int argc, const char * argv[]) {
    NODE *head=NULL;
   

    
    
    display(head);
    
    return 0;

    
}

NODE* createNode(int data){
    NODE *tmp;
    tmp=(NODE*)malloc(sizeof(NODE));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void display(NODE *head){
    NODE *tmp=head;
    while (tmp!=NULL) {
        printf("%d  ",tmp->data);
        tmp=tmp->next;
    }
}

void addFront(NODE **head, int data){
    NODE* newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}
void addLast(NODE** head, int data){
    NODE* newNode=createNode(data);
    NODE* tmp;
    
    if (*head==NULL) {
        *head=newNode;
    }
    else{
        tmp=*head;
        while (tmp->next!=NULL) {
            tmp=tmp->next;
        }
        tmp->next=newNode;
    }
}

