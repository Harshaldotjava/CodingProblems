#include <iostream>
using namespace std;

void solution1(){
    cout<<"program starts:\n";
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int m[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               bool found = false;
               for(int p = j+1;p<n;p++){
                   if(m[i][j] > m[i][p]){
                       count++; found = true;
                       break;
                   }
               }

               if( !found ){
                   for(int k=i+1;k<n;k++){
                       for(int l=0;l<n;l++){
                           if(m[i][j] > m[k][l]){
                               count++; found = true;
                               break;
                           }
                       }
                       if(found) break;
                   }
               }

            }
        }

        cout<<count<<endl;
    }

    return;

}

void solution2(){
    cout<<"solution2: enter test cases:\n";
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        int m[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        }
        int arr[n*n];
        int index = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[index] = m[i][j];
                index++;
            }
        }
        int count = 0;
        for(int i=0;i<n*n;i++){
            for(int j=i+1;j<n*n;j++){
                if(arr[i] > arr[j]){
                    count++;
                    break;
                }
            }
        }
       cout<<count<<endl; 
    }
}

int main(){
    solution2();
}


