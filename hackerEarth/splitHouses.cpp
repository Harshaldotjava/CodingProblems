#include <iostream>
using namespace std;

bool adjecentHouse(string s){
    for(int i=0,j=1;j<s.length();i++,j++){
        if(s[i] == 'H' && s[j] == 'H')
            return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s = "";
        for(int i=0;i<n;i++){
            char c;
            cin>>c; s += c;
        }
        if(!adjecentHouse(s)){
            for(int i=0;i<n;i++){
                if(s[i] == '.')
                    s[i] = 'B';
            }
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
