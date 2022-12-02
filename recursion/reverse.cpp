#include <iostream>
using namespace std;

void reverse(string &s,int n){
    if(n == 1){
        return;
    }
    char ch = s[n-1];
    reverse(s,n-1);
    for(int i = n-2;i>=0;i--){
        s[i+1] = s[i];
    }
    s[0] = ch;
    return;
}

int main(){
    string name = "harshal";
    reverse(name,name.length());
    cout<<name<<endl;
    return 0;
}
