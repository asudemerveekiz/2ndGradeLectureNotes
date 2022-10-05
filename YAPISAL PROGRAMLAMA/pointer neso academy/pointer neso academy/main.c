//
//  main.c
//  pointer neso academy
//
//  Created by Asude Ekiz on 10.12.2021.
//

#include <stdio.h>
void min_max(int a[], int length, int*minimum, int*maximum){
    int i;
    for (i=0; i<length; i++) {
        if (a[i]>*maximum) {
            *maximum=a[i];
        }
        if (a[i]<*minimum) {
            *minimum=a[i];
        }
    }

}
int* find_mid(int a[],int n){
     int *mid=&a[n/2];
    return mid;
}
int *fun(){
    
     int i=5;
    
    return &i;
}

int main(int argc, const char * argv[]) {
    int arr[]={12,34,56,87,11,5,23};
    int min;
    int max;
    int len=sizeof(arr)/sizeof(arr[0]);
    min_max(arr, len, &min, &max);
    printf("\n new min is: %d\n new max is: %d\n", min,max);
    int *mid;
    mid=find_mid(arr,len);
    printf("mid of array is: %d\n", *mid);
    int *p=fun();
    printf("\n*p=%d\n",*p);
    
    return 0;
}
