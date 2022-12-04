#include <iostream>
using namespace std;
//maximun length sub string with no adjecent repeating charater


int solution(string s){
    int max = 0;
    int count = 1;
    for(int i=0,j=1;j<s.length();i++,j++){
        if(s[i] == s[j]){
            count = 0;
        }
        else count += 2;
        if(count > max) max = count;
    }
    return max;
}

int main(){
    cout<<solution("aaaac");

    return 0;
}
