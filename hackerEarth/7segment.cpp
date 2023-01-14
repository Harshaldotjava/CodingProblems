#include <iostream>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sticks[10] = {6,2,5,5,4,5,6,3,7,6};
        n = sticks[n];
        if(n%2 != 0)
            cout<<7;
            
        for(int i=0;i<n/2;i++)
            cout<<1;
            cout<<endl;
      
    }
    return 0;
}
