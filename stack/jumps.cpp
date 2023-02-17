#include <iostream>
#include <climits>
#include <vector>
using namespace std;


vector<int> nextSmall(vector<int> arr,int n){
     vector<int> v(n,-1);
    v[n-1] = n-1;

    for(int i=n-2;i>=0;i--){
        if(arr[i+1] < arr[i]){
            v[i] = i ;
        }                
        else v[i] = v[i+1];
    }


    return v;
}

vector<int> prefixXor(vector<int> arr,int n){
    vector<int> p_sum(n,0);
    p_sum[0] = arr[0];

    for(int i=1;i<n;i++){
        int a = p_sum[i-1];
        int b = arr[i]; 
        p_sum[i] = a^b;
    }
    return p_sum;
}

int maxFromVector(vector<int> arr,int n){
    int max = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i] > max) max = arr[i];
    }

    return max;
}

int solve(vector<int> arr,int n){
    vector<int> stamina(n,0);
    vector<int> sum = prefixXor(arr,n);
    vector<int> jump_till = nextSmall(arr,n);
    stamina[0] = sum[jump_till[0]];


    for(int i=1;i<n;i++){
        int a = sum[jump_till[i]];
        int b = sum[i-1]; 
 
        if(jump_till[i] == i){
            stamina[i] = 0;
            continue;
        }
       stamina[i] = a ^ b;
    }
    for(int i=0;i<n;i++)
        cout<<stamina[i]<<" ";
    cout<<endl;
    return maxFromVector(stamina,n); 

}


int main(){
    vector<int> arr = {1,2,3,8,6};
    int result = solve(arr,arr.size());
    cout<<result<<endl;
}
