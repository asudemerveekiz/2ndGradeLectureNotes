

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;

}NODE;

void traverseForward(NODE *head);
void traverseBackward(NODE *tail);
//NODE *head; prohibited

void addfront(NODE ** head, int data);
void addLast(NODE **head, int data);
void addMiddle(NODE **head, int data);
NODE* searchNode(NODE *head, int data);
NODE* getNode(int data);
void deleteNode(NODE **head, int data);


int main(int argc, const char * argv[]) {
    
    NODE *head=NULL;
    NODE *tmp;
    int n;
    /*traverseForward(head);
    addfront(&head, 10);
    traverseForward(head);
    addfront(&head, 20);
    traverseForward(head);
    addLast(&head, 0);
    traverseForward(head);
    addLast(&head, -5);
    traverseForward(head);
    addfront(&head, 30);
    traverseForward(head);
    addfront(&head, 40);
    traverseForward(head);
    addfront(&head, 50);
    traverseForward(head);
    addLast(&head, -10);
    */
    traverseForward(head);
    addMiddle(&head, 35);
    traverseForward(head);
    addMiddle(&head, 39);
    traverseForward(head);
    addMiddle(&head, 36);
    traverseForward(head);
    addMiddle(&head, 40);
    traverseForward(head);
    addMiddle(&head, 37);
    traverseForward(head);
    addMiddle(&head, 55);
    traverseForward(head);
    addMiddle(&head, 50);
    traverseForward(head);
    deleteNode(&head, 35);
    traverseForward(head);
    deleteNode(&head, 60);
    traverseForward(head);
    
    printf("Aramak istediginiz datayi giriniz: \n");
    scanf(" %d",&n);
    tmp=searchNode(head, n);
    if (tmp==NULL) {
        printf("Aradiginiz deger bulunamadi.\n");
    }
    else{
        printf("Aradiginiz deger: %d\n",tmp->data);
        printf("Degerin adresi :%p\n", tmp);
    }

    return 0;
}


NODE* getNode(int data){
    NODE* newNode;
    newNode=(NODE *)malloc(1*sizeof(NODE));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void addfront(NODE ** head, int data){
    NODE *newNode=getNode(data);
    newNode->next=*head;
    *head=newNode;
    }

void addLast(NODE **head, int data){
    NODE *newNode=getNode(data);
    //listede bir sey olmama durumu icin asagidaki if kismini eklememiz gerekiyor
    //ya da add frontu cagirirsin
    if (*head==NULL) {
        *head=newNode;
    }
    else{
        NODE *tmp;
        tmp=*head;
        while (tmp->next!=NULL) {
            tmp=tmp->next;
        }
        tmp->next=newNode;
    }
}

void addMiddle(NODE **head, int data){
    NODE *tmp;
    NODE *newNode=getNode(data);
  
    if (*head==NULL) {
        *head=newNode;
        }
    else{
        tmp=*head;
        while ((tmp->next!=NULL) &&(tmp->next->data<data)) {
            tmp=tmp->next;
        }
        newNode->next=tmp->next;
        tmp->next=newNode;
    }
    
}

NODE* searchNode(NODE *head, int data){
    NODE *tmp;
    tmp=head;
    while ((tmp!=NULL)&&(tmp->data!=data)) {
        tmp=tmp->next;
    }
    return tmp;
}


void deleteNode(NODE **head, int data){
    NODE *tmp,*current;
    if ((*head)->data==data) {
        tmp=*head;
        *head=(*head)->next;
        free(tmp);
        printf("%d silindi\n",data);
    }
    else{
        current=*head;
        while ((current->next!=NULL)&&(current->next->data!=data)) {
            current=current->next;
            
        }
        if (current->next!=NULL) {
            tmp=current->next;
            current->next=current->next->next;
            free(tmp);
        }
        else
            printf("Silinecek deger bulunamadi.\n");
    }
    
}
                 

void traverseForward(NODE *head){
    NODE *tmp=head;
    while (tmp!=NULL) {
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}



