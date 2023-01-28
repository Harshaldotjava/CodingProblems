#include <iostream>
#include <set>
using namespace std;



int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];            
        }

        int evenSum = 0;
        int oddSum = 0;

        for(int i=0;i<n;i++){
            if(i%2 == 0)
                evenSum += arr[i];
            else
                oddSum += arr[i];
        }
        int diff = oddSum  - evenSum;
        int prefixSum[n]; 
        prefixSum[0] = arr[0];

        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + arr[i]; 
        }

        if(prefixSum[n-1] == 0){
            cout<<"YES"<<endl;
            return 0;
        }
        if(prefixSum[n-1] % 2 == 1){
            cout<<"NO"<<endl;
            return 1;
        }

        int target = diff/2;
        set<int> s;

        for(int i=0;i<n;i++){
            if(s.count(prefixSum[i] - target)){
                cout<<"YES"<<endl;
                return 0;
            }

            s.insert(prefixSum[i]);
        }

        cout<<"No"<<endl;

    }
    return 1;
}
