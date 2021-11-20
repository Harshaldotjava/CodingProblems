#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int expandBetween(char *s,int left,int right){

    while(left>=0 && right<strlen(s) && s[left]==s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}

char *longestPalindrome(char *s){
    int start = 0;
    int end = 0;

    for(int i=0;i<strlen(s);i++){

        int len1 = expandBetween(s,i,i);
        int len2 = expandBetween(s,i,i+1);
        int len = (len1>len2) ?len1 :len2;
        if(len>end-start){
            start = i - ((len-1)/2);
            end = i + (len/2);
        }
    }

    char *ptr = (char *)malloc(sizeof(char)*((end-start)+1));
    int j=0;
    for(int i=start;i<=end;i++){
        ptr[j]=s[i];
        j++;
    }
    return ptr;
}

void main(){

    char *s = longestPalindrome("babad");
    for(int i=0;i<strlen(s);i++)
        printf("%c",s[i]);
}