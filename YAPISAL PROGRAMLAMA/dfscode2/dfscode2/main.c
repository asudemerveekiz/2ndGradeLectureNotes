#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}NODE;


int push(NODE** head,int element);
int pop(NODE** head,int* element);

//main program


int main()
{
    //input no of nodes: Num
    int Num;
    printf("Enter number of nodes\n");
    scanf("%d",&Num);
    
    //create adjacency matrix
    int adj[Num][Num];
    //input adjacency matrix
    printf("Enter adjacency matrix\n");
    for(int i=0;i<Num;i++)
    {
        for(int j=0;j<Num;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    
    //DFS traversing
    //create a stack
   NODE * Stack=NULL;
    //create status array and set it to ready state
    enum{ready,waiting,processed}; //READY=0, WAITING=1,PROCESS=2
    int status[Num];
    for(int i=0;i<Num;i++)
    {
        status[i]=ready;
    }
    
    //add first node to stack
    push(&Stack,0);
    status[0]=waiting;
    int iter=NULL;
    printf("DFS traversing\n");
    
    while(Stack!=NULL)
    {
        //get a node from stack, display it and change status to processed
        pop(&Stack,&iter);
        printf("%d ",iter);
        status[iter]=processed;
        //add it's neighbours with status ready to stack
        for(int i=0;i<Num;i++)
        {
            if(adj[iter][i]==1 && status[i]==ready)
            {
                push(&Stack,i);
                status[i]=waiting;
            }
        }
    }
    printf("\n");
}


//stack functions
int push(NODE** head,int element)
{
   NODE* temp;
    temp=*head;
    *head=(NODE*)malloc(sizeof(NODE));
    if(head==NULL)
        return 1;
    (*head)->data=element;
    (*head)->next=temp;
    return 0;
}
int pop(NODE** head,int* element)
{
    if(*head==NULL)
        return 1;
    *element=(*head)->data;
    NODE* temp;
    temp=*head;
    *head=(*head)->next;
    free(temp);
    return 0;
}
  
