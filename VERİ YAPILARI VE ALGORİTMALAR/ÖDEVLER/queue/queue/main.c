//
//  main.c
//  queue
//
//  Created by Asude Ekiz on 17.04.2022.
//
#define MAX 10
#include <stdio.h>

int front=-1;
int rear=-1;
int array[MAX];
int isEmpty(void);
int isFull(void);
void enqueue(int data);
void printArray(int *p);
void dequeue(int data);



int main(int argc, const char * argv[]) {
    printArray(array);
    printf("\nfront: %d, rear: %d\n",front, rear);
    enqueue(1);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(2);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    dequeue(1);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(3);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(4);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(5);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(6);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(7);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(8);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(9);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(10);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    enqueue(11);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    dequeue(11);
    printArray(array);
    printf("\nfront: %d, rear:%d \n",front,rear);
    
}
    

int isEmpty(){
    if (front==-1 &&rear==-1) {
        return 1;
    }
    else
        return 0;
    
}
int isFull(){
    if (rear==MAX-1) {
        return 1;
    }
    else
        return 0;
}

void enqueue(int data){
    if ((rear+1)%MAX==front) {
        printf("Cant enqueue!\n");
        return;
    }
    else if (isEmpty()){
        front=0;
        rear=0;
        
    }
    else{
        rear=(rear+1)%MAX;
    }
    array[rear]=data;
}
void dequeue(int data){
    if (isEmpty()) {
        printf("Cant dequeue!\n");
        return;
    }
    else if(rear==front) {//it means there is only 1 element in the array
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAX;
        //you don't need to change the element which you dequeue because if we do enqueue we will write it
        //on it so it doesn't really matter
    }
    
}

void printArray(int *p){
    int i;
    printf("\nYour array is:\n");
    for (i=0; i<MAX; i++) {
        printf("%d ",p[i]);
    }
}
    

