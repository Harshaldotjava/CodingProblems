#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    
    int i,j,len,maxlen=0;
    int ctr[256] = {0};
   
    for(i=0; s[i]!=0;i++){
        len = 0;
        memset(ctr,0,sizeof(ctr));
        for(j=i;s[j]!=0;j++){
            if(ctr[s[j]]==0){
                ctr[s[j]]++;
                len++;
            }else{
                break;
            }
        }
        if(len>maxlen){
            maxlen = len;
        }
    }
    return maxlen;
}

int solution(char *s){
     int i=0;
    int j=0;
    int max = 0;
    int len = 0;
    int ctr[256]={0};
    memset(ctr,0,sizeof(ctr));
    while(s[j]!=0){
        if(ctr[s[j]]==0){
            ctr[s[j]]++;
            len++;
            j++;
        }else{
            i++;
            len = 0;
            memset(ctr,0,sizeof(ctr));
            j=i;
        }
        max = len;
    }
    return max;
}

void main(){
    char *s = "c";
    printf("%d\n",lengthOfLongestSubstring(s));
    printf("%d\n",solution(s));
    
    
}