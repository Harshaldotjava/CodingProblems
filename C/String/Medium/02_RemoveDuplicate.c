#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* removeDups(char* s) { 
    //code here
    int size = sizeof(s)/sizeof(*s);
    int ctr[258]={0};
    char *ptr = (char *)malloc(sizeof(char)*size);
    int j=0;
    for(int i=0;s[i]!=0;i++){
        if(ctr[s[i]]==0){
            ptr[j]= s[i];
            ctr[s[i]]++;
            j++;
        }else{

        }
    }
   
    return ptr;
}


int main(){
    char *s = "gfg";
    char *arr = removeDups(s);

    return 0;
}