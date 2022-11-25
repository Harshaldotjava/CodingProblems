#include <stdio.h>



int summation(int number){
    int sum = 0;

    while(number != 0){
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

void printArray(int array[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
    printf("\n");
}



int main(){
    int n; printf("enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    int result[n];
    for(int i=0;i<n;i++){
        printf("enter element no %d: ",i+1);
        scanf("%d",&arr[i]);
        result[i] = summation(arr[i]);
    }

    printf("Elements: \n");
    printArray(arr,n);
    printf("Output: \n");
    printArray(result,n);


    return 0;
}
