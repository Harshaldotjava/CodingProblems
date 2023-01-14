#include <iostream>
using namespace std;


int main(){
    string s;
    cout<<"enter code\n";
    cin>>s;

    char vowels[] = {'A','E','I','O','U','Y'};

    for(int i=0;i<6;i++){
        if(s[2] == vowels[i]){
            cout<<"INVALID"<<endl;
            return 0;
        }
    }

    for(int i=0;i<s.size();i++){
        if(i!=2 && i!=1 && i!=6 && i!=5){
            int val = s[i] - '0';
            int val2 = s[i+1] - '0';
            
            if((val+val2)%2 == 1){
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
    }

    cout<<"VALID"<<endl;
    return 0;
    
}
