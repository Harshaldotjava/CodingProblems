#include <iostream>
using namespace std;



int main(){
   
    int t;
    cout<<"enter test cases: ";
    cin>>t; cout<<endl;

    while(t--){
        int x,l,n;
        cin>>x>>l>>n;
        int manaPoints = 0;
        for(int i=0;i<n;i++){
            if(x > l) break;
            if(x == 0) break;
            x--;
            x = x*2;
            manaPoints++;
        }

        cout<<manaPoints<<endl;
    }
    return 0;
}
