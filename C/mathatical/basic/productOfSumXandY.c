// Given a positive integer n. Find the sum of product of x and y such that floor(n/x) = y .
#include <stdio.h>
#include <stdlib.h>

int findSum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum += i*(n/i);
    }
    return sum;
}


int main(){
    int n = findSum(5);
    printf("%d",n);

    return 0;
}