#include <iostream>
using namespace std;


int main(){
    int t;
    cout<<"enter test"<<endl;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int mat[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                for(int p=i;p<n;p++){
                    for(int q=j;q<n;q++){
                        if(mat[i][j] > mat[p][q])
                            count++;
                    }
                }


            }
        }
        cout<<count<<endl;
    }

}
