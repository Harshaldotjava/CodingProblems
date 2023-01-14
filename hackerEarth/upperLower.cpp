#include <iostream>
#include <cctype>
using namespace std;


int main(){
    string s = "abCdEfGH";

    for(int i=0;i<s.size();i++){
        if(s[i] == toupper(s[i]))
           s[i] = tolower(s[i]); 
        else
            s[i] = toupper(s[i]); 
        
    }
    cout<<s<<endl;

    return 0;
}
