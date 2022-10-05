//
//  main.c
//  projesonson
//
//  Created by Asude Ekiz on 7.01.2022.
//

//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct student{ //ogrencilerin oldugu struct
    int  id;
    char name[20];
    char surname[20];
    int lesson_num;
    int credit;
    struct student *next;
    struct student *before;
    
}STUDENT;


typedef struct lesson{ //derslerin oldugu struct
    int *student;
    char code[50];
    char name[50];
    int credit;
    int capacity;//anlık kapasite
    int quota;//maksimum kapasite
    struct lesson *next;

}LESSON;

typedef struct  studentLessonRecord{ //ogrenciderskayıt structı
    int listID;
    char name[50];
    int stID;
    char date[50];
    char state[50];
    struct studentLessonRecord *next;
}RECORD;


void splitStudent(STUDENT *holder, char buff[255],char delimeter[2]);
void splitLesson(LESSON *holder,char buff[255],char delimeter[2]);
void splitRecord(RECORD *holder, char buff[255],char delimeter[2]);

STUDENT *studentRead(char file[50],char delimeter[2],STUDENT **tail);
LESSON *lessonRead(char file[50],char delimeter[2]);
RECORD *recordRead(int max_lesson, int max_credit, STUDENT* headStudent, LESSON *headLesson, char file[50],char delimeter[2]);
void printStudent(STUDENT *head);
void printStudentVol2(STUDENT *tail);
void printLesson(LESSON *head);
void printRecord(RECORD *head);
void addStudent(STUDENT **head, STUDENT **tail);
void deleteStudent(STUDENT **head);
void addLesson(LESSON **head);
void deleteLesson(LESSON **head,RECORD **headR);

int AddStudentToLesson(char *code, int studentid, int max_credit,int max_lesson, LESSON *headLesson, STUDENT *headStudent);
int DeleteStudentFromLesson(char *code, int studentid, int max_credit,int max_lesson, LESSON *headLesson, STUDENT *headStudent);
void addRecord(RECORD **head,char code[20],int id,char state[20]);
void updateRecord(RECORD **head,char code[20],int id,char state[20]);
void FileWriteStudent(STUDENT *head, char FileName[50], char delimeter);
void FileWriteLesson(LESSON *head, char FileName[50], char delimeter);
void FileWriteRecord(RECORD *head, char FileName[50],char delimeter);
void PrintLessonsStudent(LESSON *head);
void PrintStudentLessons(LESSON *head);
void FileForLessonStudent(LESSON *head,char delimeter);
void FileForStudentLesson(LESSON *head,char delimeter[2]);





int main(int argc, const char * argv[]){
    
   
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
      printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
      printf("\n\t\t\t        =                  WELCOME                  =");
      printf("\n\t\t\t        =                    TO                     =");
      printf("\n\t\t\t        =           Student Course Record           =");
      printf("\n\t\t\t        =                   SYSTEM                  =");
      printf("\n\t\t\t        =         created by Asude Merve Ekiz       =");
      printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
      printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    
    int ID;
    char code[20];
    int max_credit;
    int max_lesson;
    
    printf("\n UYARI:\n\tProgram menulere girdiginde coktan mevcut bulunan dersler.txt, ogrenciler.txt, OgrenciDersKayit.txt dosyalarından okuma yapmıs olacagı icin max kredi ve max lesson degerlerinin 20 girilmesi onerilir.\n \n");
    
    printf("Please enter the max credit value:\n");
    scanf(" %d",&max_credit);
    printf("Please enter the max lesson value:\n");
    scanf(" %d",&max_lesson);
    
    
    int choose=-1;
    int subchoose=-1;
    int control;
    STUDENT *headStudent;
    STUDENT *tailStudent=(STUDENT*)malloc(sizeof(STUDENT));
    headStudent=studentRead("ogrenciler.txt", ",\0", &tailStudent);
    LESSON *headLesson;
    headLesson=lessonRead("dersler.txt", ",\0");
    RECORD *headRecord;
    headRecord=recordRead(max_lesson, max_credit,headStudent,headLesson,"OgrenciDersKayit.txt", ",\0");
    
    
    while(choose!=6){
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
          printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
          printf("\n\t\t\t        =                  WELCOME                  =");
          printf("\n\t\t\t        =                    TO                     =");
          printf("\n\t\t\t        =           Student Course Record           =");
          printf("\n\t\t\t        =                   SYSTEM                  =");
          printf("\n\t\t\t        =         created by Asude Merve Ekiz       =");
          printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
          printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        
        
        
        
        
        printf("===================PLEASE ENTER THE PROCEDURE YOU WANT TO DO=====================\n");
        printf("1)Student Options\n");
        printf("2)Lesson Options\n");
        printf("3)Record Options\n");
        printf("4)View the student list of the selected lesson\n");
        printf("5)List all courses taken by a student whose number is given\n");
        printf("6)Exit\n");
       
        printf("Your choose: ");
        scanf("%d",&choose);
        if(choose==1){
            printf("\n\n===================Student Options=====================\n");
            printf("\nFor add a new student please choose 1\n");
            printf("\nFor delete a student please choose 2\n");
    
            printf("Your choose:");
            scanf("%d",&subchoose);
            printf("\n");
            switch(subchoose){
                case 1:
                    addStudent(&headStudent,&tailStudent);
                    printStudent(headStudent);
                    FileWriteStudent(headStudent, "/Users/asude/PROJE/ogrenciler.txt", ',');
                    break;
                case 2:
                    deleteStudent(&headStudent);
                    printStudent(headStudent);
                    FileWriteStudent(headStudent, "/Users/asude/PROJE/ogrenciler.txt", ',');
                    break;
                
                default:
                    printf("You have logged in invalid, try again.Returning the main menu.");
            }
        }
        else if(choose==2){
            printf("\n\n==================Lesson Options=====================\n");
            printf("\nFor add a new lesson please choose 1\n");
            printf("\nFor delete a lesson please choose 2\n");
         

            printf("Your choose: ");
            
            scanf("%d",&subchoose);
            printf("\n");
            switch(subchoose){
                case 1:
                    addLesson(&headLesson);
                    printLesson(headLesson);
                    FileWriteLesson(headLesson, "/Users/asude/PROJE/dersler.txt", ',');
                    
                   
                  
                    break;
                case 2:
                   deleteLesson(&headLesson,&headRecord);
                    printLesson(headLesson);
                    printRecord(headRecord);
                    FileWriteLesson(headLesson, "/Users/asude/PROJE/dersler.txt", ',');
                    
                  
                    break;
                
                default:
                    printf("You have logged in invalid, try again.Returning the main menu.");
            }
        }
        else if(choose==3){
            printf("\n\n==================Record Options=====================\n");
            
            printf("Please enter your id: ");
            scanf("%d",&ID);
            
            printf("\nFor add a new lesson to your program please choose 1:\n");
            printf("\nFor delete a lesson from your program please choose 2:\n");
            scanf("%d",&subchoose);
            printf("\n");
            switch(subchoose){
                case 1:
                    printf("Please enter the lesson's code which you want to add to your program: ");
                    scanf("%s",code);
                    control=AddStudentToLesson(code, ID, max_credit, max_lesson, headLesson, headStudent);
                    if (control) {
                        addRecord(&headRecord, code, ID, "kayitli");
                        printRecord(headRecord);
                        FileWriteRecord(headRecord, "/Users/asude/PROJE/OgrenciDersKayit.txt", ',');
                    }
                    
                    break;
                case 2:
                    printf("Please enter the lesson's code which you want to remove from your program: ");
                    scanf("%s",&code);
                    control=DeleteStudentFromLesson(code,ID,max_credit,max_lesson,headLesson,headStudent);
                    if (control) {
                        updateRecord(&headRecord,code,ID,"sildi");
                        printRecord(headRecord);
                        FileWriteRecord(headRecord, "/Users/asude/PROJE/OgrenciDersKayit.txt", ',');
                    }
                    break;
                
                default:
                    printf("You have logged in invalid, try again.Returnin the main menu.");
            }
            }
        else if (choose==4){
            FileForLessonStudent(headLesson,' ');
        }
        else if(choose==5){
            //PrintStudentLessons(headLesson);
            FileForStudentLesson(headLesson,'  ');
        }
        
        }
        
        printf("_____________________________________________________________________\n                      RETURNING THE MAIN MENU               _____________________________________________________________\n\n");
    

    
   
    
    return 0;
}


void splitStudent(STUDENT *holder, char buff[255],char delimeter[2]){
    char *token;
    token=strtok(buff, delimeter);
    holder->id=atoi(token);
    token=strtok(NULL,delimeter);
    strcpy(holder->name,token);
    token=strtok(NULL,delimeter);
    strcpy(holder->surname,token);
    token=strtok(NULL,delimeter);
    holder->lesson_num=atoi(token);
    token=strtok(NULL,delimeter);
    token[strlen(token)-1]='\0';
    holder->credit=atoi(token);
}

void splitLesson(LESSON *holder,char buff[255],char delimeter[2]){
    char *token;
    token=strtok(buff, delimeter);
    strcpy(holder->code,token);
    token=strtok(NULL,delimeter);
    strcpy(holder->name,token);
    token=strtok(NULL,delimeter);
    holder->credit=atoi(token);
    token=strtok(NULL,delimeter);
    token[strlen(token)-1]='\0';
    holder->quota=atoi(token);
    holder->capacity=0;

}

void splitRecord(RECORD *holder, char buff[255],char delimeter[2]){
    char *token;
    token=strtok(buff, delimeter);
    holder->listID=atoi(token);
    token=strtok(NULL,delimeter);
    strcpy(holder->name,token);
    token=strtok(NULL,delimeter);
    holder->stID=atoi(token);
    token=strtok(NULL,delimeter);
    strcpy(holder->date,token);
    token=strtok(NULL,delimeter);
    token[strlen(token)-1]='\0';
    strcpy(holder->state,token);
}
int AddStudentToLesson(char *code, int studentid, int max_credit,int max_lesson, LESSON *headLesson, STUDENT *headStudent){
    int i,j ;
    while (headStudent->id!=studentid && headStudent->next!=NULL) {
        headStudent=headStudent->next;
    }
    if (headStudent->id!=studentid) {
       //printf("There is not a student as that id");
        return 0;
    }
    
    while ((strcmp(headLesson->code, code))&& headLesson->next!=NULL) {
        headLesson=headLesson->next;
    }
    
    if (strcmp(headLesson->code, code)) {
        printf("There is not a lesson as that code");
        return 0;
    }
    
    if ((max_lesson>headStudent->lesson_num )&&(max_credit>(headLesson->credit + headStudent->credit)) ) {
        if (headLesson->quota!=headLesson->capacity) {
            i=0;
            while (i<headLesson->capacity&&headLesson->student[i]<studentid) {
                i++;
            }
            if (studentid==(headLesson->student[i])) {
                printf("This student has already recorded\n");
            }
            if (i==headLesson->capacity) {
                headLesson->student[i]=studentid;
            }
            else{
                j=headLesson->capacity;
                while (j>i) {
                    --j;
                    headLesson->student[j+1]=headLesson->student[j];
                }
                headLesson->student[j]=studentid;
            }
            
            headStudent->lesson_num+=1;
            headLesson->capacity+=1;
            headStudent->credit+=headLesson->credit;
            
            
            return 1;
        
        }
        else{
            printf("\nLesson capacity is full!\n");
            return 0;
            
        }
    }
    else{
        printf("\nThis student can't take any lesson. Student's lesson capacity is full!\n");
        return 0;
    }
}

int DeleteStudentFromLesson(char *code, int studentid, int max_credit,int max_lesson, LESSON *headLesson, STUDENT *headStudent){
    
    int i,j ;
    while (headStudent->id!=studentid && headStudent->next!=NULL) {
        headStudent=headStudent->next;
    }
    
    if (headStudent->id!=studentid) {
        printf("There is not a student as that id");
        return 0;
    }
    
    while ((strcmp(headLesson->code, code))&& headLesson->next!=NULL) {
        headLesson=headLesson->next;
    }
    
    if (strcmp(headLesson->code, code)) {
        printf("There is not a lesson as that code");
        return 0;
    }
    i=0;
    while (i<headLesson->capacity && headLesson->student[i]<studentid) {
        i++;
    }
    if (studentid==(headLesson->student[i])) {
        for (j=i; j<headLesson->capacity; j++) {
            headLesson->student[j]=headLesson->student[j+1];
        }
        
        headLesson->student=realloc(headLesson->student, (headLesson->capacity-1)*sizeof(headLesson->student));
        
        headStudent->lesson_num-=1;
        headLesson->capacity-=1;
        headStudent->credit=headStudent->credit - headLesson->credit;
        return 1;
    }
    else
        return 0;

}



STUDENT *studentRead(char file[50],char delimeter[2],STUDENT **tail){
    FILE *fp=fopen(file,"r");
    char buff[255];
    STUDENT *head=(STUDENT*)malloc(sizeof(STUDENT));
    STUDENT *curr;
    STUDENT *prev;
    if (fgets(buff, 255, fp)==NULL) {
        printf("File couldn't open");
        }
    else{
        splitStudent(head, buff, delimeter);
    }
    head->before=NULL;
    prev=head;
    while (fgets(buff,255,fp)!=NULL) {
   
        curr=(STUDENT*)malloc(sizeof(STUDENT));
        prev->next=curr;
        splitStudent(curr, buff, delimeter);
        curr->before=prev;
        prev=curr;
    }
    prev->next=NULL;
    *tail=prev;
    fclose(fp);
    return head;
}

LESSON *lessonRead(char file[50],char delimeter[2]){
    FILE *fp=fopen(file,"r");
    char buff[255];
    LESSON *head=(LESSON*)malloc(sizeof(LESSON));
    LESSON *prev;
    LESSON *current;

    
    if (fgets(buff, 255, fp)==NULL) {
        printf("File couldn't open.\n");
       }
    else{
        splitLesson(head, buff, delimeter);
        head->student=(int*)calloc(head->quota, sizeof(int));
        
    }
    
   
    prev=head;
    while (fgets(buff, 255, fp)!=NULL) {
        current=(LESSON*)malloc(sizeof(LESSON));
        prev->next=current;
        splitLesson(current, buff, delimeter);
        current->student=(int*)calloc(current->quota, sizeof(int));
        prev=current;
    }
    prev->next=NULL;
    fclose(fp);
    return head;
    
   }
RECORD *recordRead(int max_lesson, int max_credit, STUDENT* headStudent, LESSON *headLesson, char file[50],char delimeter[2]){
    FILE *fp=fopen(file,"r");
    char buff[255];
    RECORD *head=(RECORD*)malloc(sizeof(RECORD));
    RECORD *prev;
    RECORD *current;
    
    if (fgets(buff, 255, fp)==NULL) {
        printf("File couldn't open.\n");
       }
    else{
        splitRecord(head, buff, delimeter);
        if(!strcmp(head->state,"kayitli")){
            AddStudentToLesson(head->name, head->stID, max_credit, max_lesson, headLesson, headStudent);
        }
       
    }
    
    prev=head;
    while (fgets(buff, 255, fp)!=NULL) {
        current=(RECORD*)malloc(sizeof(RECORD));
        prev->next=current;
        splitRecord(current, buff, delimeter);
        prev=current;
        if(!strcmp(prev->state,"kayitli")){
                AddStudentToLesson(prev->name, prev->stID, max_credit, max_lesson, headLesson, headStudent);
        }
        // if(!strcmp(head->state,"sildi") ise
        //studentRecorddelete yap
    }
    prev->next=NULL;
    fclose(fp);
    return head;
    
   }


void printStudent(STUDENT *head){
       while(head!=NULL){
           printf("\nID: %d\nName: %s %s\nLesson: %d\nCredit: %d",head->id,head->name,head->surname,head->lesson_num,head->credit);
           head = head->next;
       }
   }


 

   void printLesson(LESSON *head){
       while(head!=NULL){
           printf("\nCode: %s\nName: %s\nCredit: %d\nQuota: %d",head->code,head->name,head->credit,head->quota);
           int i;
           for (i=0; i<head->capacity; i++) {
               printf("\nStudent id: %d", head->student[i]);
           }
           head = head->next;
           printf("\n--------------------------------\n");
       }
   }

   void printRecord(RECORD *head){
       while(head!=NULL){
           printf("\nlistID: %d\nName: %s\nstID: %d\nDate: %s\nState: %s",head->listID,head->name,head->stID,head->date,head->state);
           head = head->next;
           printf("\n-------------------------------");
       }
   }
void addStudent(STUDENT **head, STUDENT **tail){
        STUDENT *newStudent= (STUDENT*)malloc(sizeof(STUDENT));
        STUDENT *tmp = *head;
        
        printf("\nPlease enter the new student's ID: ");
        scanf("%d",&newStudent->id);
    //If the new student will be the head student
        if(newStudent->id < tmp->id){
            newStudent->before = tmp->before; //null olacak
            newStudent->next = tmp;
            *head = newStudent;
        }
   
        tmp = tmp->next;
        while(tmp->id < newStudent->id && tmp->next != NULL){
            tmp = tmp->next;
        }
        if(tmp->id > newStudent->id){
            tmp->before->next = newStudent;
            newStudent->before = tmp->before;
            tmp->before = newStudent;
            newStudent->next = tmp;
        }
        else if(tmp->id == newStudent->id){
            printf("The student which you enter is already exist.\n");
            return;
        }
        else{
            newStudent->next = tmp->next;        //null
            tmp->next = newStudent;
            newStudent->before = tmp;
            *tail = newStudent;
        }
        
        printf("Student name: ");
        scanf(" %s",&newStudent->name);
        printf("Student surname: ");
        scanf(" %s",&newStudent->surname);
        newStudent->lesson_num = 0;
        newStudent->credit = 0;
        
        
        }

void deleteStudent(STUDENT **head){
    STUDENT *tmp=*head;
    STUDENT* current;
    int willdelete=0;
    printf("\nPlease enter the ID of the student to be deleted:\n");
    scanf("%d",&willdelete);
    //If this student will be the head student
    if(willdelete == tmp->id){
        tmp->next->before=NULL;
        *head=tmp->next;
        free(tmp);
       
        printf("\nThe student which you want to delete is deleted.\n");
}
    
    else{
        current=*head;
        while ((current->next!=NULL)&&(current->id!=willdelete)) {
            current=current->next;
        }
        if (current->next!=NULL) {
            //buraya girerse eşleşme oldu ve öğrenci silinecek demek
            current->before->next=current->next;
            current->next->before=current->before;
            free(current);
            printf("\nThe student which you want to delete is deleted.\n");
        }
        else if(current->next==NULL){
            if (current->id==willdelete) {
                current->before->next=NULL;
                free(current);
                printf("\nThe student which you want to delete is deleted.\n");
            }
            else{
                printf("\nThe student which you want to delete is can not find.\n");
            }
                
        }
        }
 }




void addLesson(LESSON **head){
    
    LESSON *newLesson= (LESSON*)malloc(sizeof(LESSON));
    LESSON *tmp = *head;
    fflush(stdin);
    printf("\nPlease enter the lesson's code which you want to open : ");
    scanf(" %s",&newLesson->code);
   
    
    if (strcmp(newLesson->code, tmp->code)<0) {
        newLesson->next = tmp;
        *head = newLesson;
    }
    
    tmp=tmp->next;
    while((tmp->next != NULL)&& (strcmp(newLesson->code, tmp->next->code)>0) ){
        tmp = tmp->next;
    }
    if (tmp->next==NULL) {
        tmp->next=newLesson;
        newLesson->next=NULL;
        }
    else if((strcmp(newLesson->code, tmp->next->code)<0)){
        newLesson->next=tmp->next;
        tmp->next = newLesson;
      }
    else{
        printf("The lesson you want to add is already exist.\n");
        return;

    }
    
    printf("Lesson's credit: ");
    scanf(" %d",&(newLesson->credit));
    printf("Lesson's quota: ");
    scanf(" %d",&(newLesson->quota));
    printf("Lesson's name: ");
    scanf(" %s",&(newLesson->name));
    
    
    }

void addRecord(RECORD **head,char code[20],int id, char state[20]){
    
    RECORD *newRecord= (RECORD*)malloc(sizeof(RECORD));
    RECORD *tmp = *head;
    
    if (*head==NULL) {
        newRecord->next=NULL;
        newRecord->listID=10000;
        strcpy(newRecord->name, code);
        newRecord->stID=id;
        strcpy(newRecord->date, "07.01.2022");
        *head=newRecord;
        return;

    }
    
    while (tmp->next!=NULL) {
        tmp=tmp->next;
    }
    
    newRecord->next=NULL;
    newRecord->listID=tmp->listID+1;
    strcpy(newRecord->name, code);
    newRecord->stID=id;
    strcpy(newRecord->date, "07.01.2022");
    tmp->next=newRecord;
    strcpy(newRecord->state, state);
    
    }

void updateRecord(RECORD **head,char code[20],int id,char state[20]){
    RECORD *tmp=*head;
    while ((tmp->next!=NULL)&&(tmp->name!=code)&&(tmp->stID!=id)) {
        tmp=tmp->next;
    }
   
    if (tmp->next==NULL) {
        addRecord(&tmp, code, id, "kayitli");
    }
    else{
        strcpy(tmp->state, state);
        strcpy(tmp->date, "07.01.2022");
    }
}


void deleteLesson(LESSON **head,RECORD **headR){
    LESSON *tmp;
    LESSON *current;
    char code[20];
    int i;
    printf("Please enter the lesson's code which you want to delete: \n");
    scanf(" %s",code);
    if (!strcmp((*head)->code, code)) {
        tmp=*head;
        for (i=0; i<tmp->capacity; i++) {
            updateRecord(headR, code, tmp->student[i], "ders kapandi");
        }
        *head=(*head)->next;
        free(tmp);
       
        printf("The lesson which you want to delete is deleted.\n");
    }
    else{
        current=*head;
        while ((current->next!=NULL)&&(strcmp(current->next->code,code))) {
            current=current->next;
            
        }
        if (current->next!=NULL) {
            tmp=current->next;
            for (i=0; i<tmp->capacity; i++) {
                updateRecord(headR, code, tmp->student[i], "ders kapandi");
            }
            current->next=current->next->next;
          
            free(tmp);
            printf("The lesson which you want to delete is deleted.\n");
        }
        else
            printf("\nYou can't delete the lesson which is not exist.\n");
    }
    
}



void FileWriteStudent(STUDENT *head, char FileName[50], char delimeter){
    FILE *fp=fopen(FileName,"w");
    char tmp [50];
    while (head!=NULL) {
        sprintf(tmp, "%d",head->id);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        fputs(head->name,fp);
        fputc(delimeter,fp);
        fputs(head->surname,fp);
        fputc(delimeter,fp);
        sprintf(tmp, "%d",head->lesson_num);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        sprintf(tmp, "%d",head->credit);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        fputc('\n',fp);
        head=head->next;
    }
    fclose(fp);
    return ;
}

void FileWriteLesson(LESSON *head, char FileName[50], char delimeter){
    FILE *fp=fopen(FileName,"w");
    char tmp [50];
    while (head!=NULL) {
        fputs(head->code,fp);
        fputc(delimeter,fp);
        fputs(head->name,fp);
        fputc(delimeter,fp);
        sprintf(tmp, "%d",head->credit);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        sprintf(tmp, "%d",head->quota);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        fputc('\n',fp);
        head=head->next;
    }
    fclose(fp);
    return ;
}

void FileWriteRecord(RECORD *head, char FileName[50],char delimeter){
    FILE *fp=fopen(FileName,"w");
    char tmp [50];
    while (head!=NULL) {
        sprintf(tmp, "%d",head->listID);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        fputs(head->name, fp);
        fputc(delimeter,fp);
        sprintf(tmp, "%d",head->stID);
        fputs(tmp,fp);
        fputc(delimeter,fp);
        fputs(head->date, fp);
        fputc(delimeter,fp);
        fputs(head->state, fp);
        fputc(delimeter,fp);
        fputc('\n',fp);
        head=head->next;
    }
    fclose(fp);
    return;
}

void PrintLessonsStudent(LESSON *head){
    char code[20];
    int i;
    LESSON *tmp=head;
    printf("Please enter the lessons code to see it's student list:\n");
    scanf("%s",code);
    while ((tmp!=NULL) &&(strcmp(code, tmp->code))) {
      
        tmp=tmp->next;
    }
    if (tmp==NULL) {
        printf("No lesson match\n");
    }
    else{
        for (i=0; i<=tmp->capacity; i++) {
            printf("%d\n",tmp->student[i]);
        }
    }
     
}

void FileForLessonStudent(LESSON *head,char delimeter){
   
    LESSON *tmp;
    tmp=head;
    int i;
    char code[20];
    char userfile[20];
    char psodoid[20];
    char header[20]={"Class List\n"};
    FILE *fp = NULL;
    printf("Please enter the lessons code to see it's student list:\n");
    scanf("%s",code);
    while ((tmp!=NULL) &&(strcmp(code, tmp->code))) {
      tmp=tmp->next;
    }
    
    
    if (tmp==NULL) {
        printf("Can not find a lesson as that code, please try again\n");
    }
    else{
        sprintf(userfile, "%s.txt", code);
        fp = fopen(userfile, "w");
        printf("Your lesson list file created successfully\n");
        fprintf(fp,"%s", header);
        for (i=0; i<tmp->capacity; i++) {
            sprintf(psodoid, "%d",tmp->student[i]);
            fputs(psodoid,fp);
            fputc(delimeter,fp);
            fputc('\n',fp);
        }
    
        }
    fclose(fp);
    }


void PrintStudentLessons(LESSON *head){
    int id;
    int i;
    int b=0;
    printf("Please enter the id of the student which you want to see his/her lessons: \n");
    scanf("%d",&id);
    LESSON *tmp;
    tmp=head;
    printf("Student's Lessons:\n");
    int flag=0;
    while (tmp->next!=NULL) {
        for (i=0; i<tmp->capacity; i++) {
            if (tmp->student[i]==id) {
                flag=1;
            }
            
        }
        if (flag==1) {
            printf("%s\n",tmp->code);
            flag=0;
            b=1;
        }
        tmp=tmp->next;
       
    }
    if (b==0) {
        printf("\nThis student is not taking any lessons\n");
    }
 
}

void FileForStudentLesson(LESSON *head,char delimeter[2]){
    
    int id,i;
    LESSON *tmp;
    tmp=head;
    int flag=0;
    int b=0;
    char psodoid[20];
    char userfile[20];
    
    char header[20]={"Student's Courses\n"};
    FILE *fp = NULL;
    
    printf("Please enter the id of the student which you want to see his/her lessons: \n");
    scanf("%d",&id);
    
    sprintf(psodoid, "%d", id);
    sprintf(userfile, "%s.txt", psodoid);
    fp = fopen(userfile, "w");
    
    printf("Your Student's Courses list file created successfully\n");
    fprintf(fp,"%s", header);
   
        
    while (tmp->next!=NULL) {
        for (i=0; i<tmp->capacity; i++) {
            if (tmp->student[i]==id) {
                flag=1;
            }
            
        }
        if (flag==1) {
            fputs(tmp->code, fp);
            fputc(delimeter,fp);
            fputc('\n',fp);

            flag=0;
            b=1;
        }
        tmp=tmp->next;
       
    }
    fclose(fp);
    if (b==0) {
        printf("\nThis student is not taking any lessons\n");
        return;
    }
    

}
