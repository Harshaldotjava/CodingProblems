#include <iostream>
using namespace std;


int main(){
   int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int x = 0;
        int y = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'z') x++;
            else y++;
        }

        if(2*x == y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 

    return 0;
}
