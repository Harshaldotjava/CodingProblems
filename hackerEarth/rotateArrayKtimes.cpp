#include <iostream>
using namespace std;


void reverse(int *arr,int low,int high){
    while(low < high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++; high--;
    }
    return;
}
void solution1(){
    cout<<"enter test cases: \n";
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        reverse(arr,0,n-1);
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }


}
void solution2(){
    cout<<"enter test cases: \n";
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        for(int i=0;i<n;i++){
            int p = arr[(i + (n-k)) % n];
            cout<<p<<" ";
        }
        cout<<endl;
    }


}
int main(){
    solution2();
}
