//Rotate the Array from given index d;

#include <stdio.h>
#include <stdlib.h>

int *rotateArray(int arr[],int n,int d){

    int index=0;
    int *ptr = (int *)malloc((sizeof(int)*n));

    for(int i=d;i<n;i++){
        ptr[index]=arr[i];
        index++;
    }
    for(int i=0;i<d;i++){
        ptr[index]=arr[i];
        index++;
    }
    return ptr;
}

int main(){

    int arr[]={1,2,3,4,5};
    int size = sizeof(arr)/ sizeof(*arr);
    int *newArr = rotateArray(arr,size,4);
    for(int i=0;i<5;i++){
        printf("%d ",newArr[i]);
    }
}