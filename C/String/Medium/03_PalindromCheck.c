#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int isPalindrom(char *s){
    int size = sizeof(s)/sizeof(*s);
    int i=0;
    int j= strlen(s)-1;
    int ispalin = -1;
    while(i<=j){
        if(s[i]==s[j]){
            ispalin = 1;
            i++;
            j--;
        }else{
            ispalin = -1;
            break;
        }
    }
    return ispalin;
}

int main(){
    char *p = "malam";
    if(isPalindrom(p)==1){
        printf("true");
    }
    else{
        printf("false");
    }
}