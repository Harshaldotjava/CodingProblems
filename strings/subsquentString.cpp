#include <iostream>
using namespace std;

bool sub(string s, string t){
    int sPointer = 0;
    for(int i=0;i<t.size();i++){
        if(sPointer == s.size())
            return true;
        if(s[sPointer] == t[i])
            sPointer ++;
    }

    if(sPointer == s.size())
        return true;
    return false;
}


int main(){

    cout<<sub("axe","ahbgdc");

    return 0;
}
