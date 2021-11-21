// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x){
    int n = x;
    int rev = 0;
    int last;
    if(x<0){
        return false;
    }
    while(n!=0){
        last = n%10;
        rev = rev *10+last;
        n /= 10;
    }
    if(rev == x)
        return true;
    else//
        return false;
}


int main(){
    if(isPalindrome(1234567899)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}