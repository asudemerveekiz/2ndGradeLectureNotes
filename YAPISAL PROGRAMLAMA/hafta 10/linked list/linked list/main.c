//
//  main.c
//  linked list
//
//  Created by Asude Ekiz on 12.12.2021.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE;
void traverseForward(NODE *head);
void traverseBackward(NODE *tail);
int main(int argc, const char * argv[]) {
 
    NODE *head;
    NODE *tmp;
    NODE *tail;
   
    NODE node1; node1.data=3;
    NODE node2; node2.data=4;
    NODE node3; node3.data=5;
    NODE node4; node4.data=6;
    
    head=&node1;
    tail=&node4;

    node1.next=&node2;
    node1.prev=NULL;
    
    node2.next=&node3;
    node2.prev=&node1;
    node3.next=&node4;
    node3.prev=&node2;
    node4.next=NULL;
    node4.prev=&node3;
    traverseForward(head);
    traverseBackward(tail);
    


    return 0;
}


/*void addNode{
    
}

void deleteNode{
    
}*/

void traverseForward(NODE *head){
    NODE *tmp=head;
    while (tmp!=NULL) {
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}

void traverseBackward(NODE *tail){
    NODE *tmp=tail;
    while (tmp!=NULL) {
        printf("%d ", tmp->data);
        tmp=tmp->prev;
    }
    printf("\n");
}

