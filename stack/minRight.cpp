#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> rightMins(int arr[],int n){
    vector<int> mins;
    stack<int> st;


    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>arr[i])
            st.pop();
        if(st.empty())
            mins.push_back(-1);
        else 
            mins.push_back(st.top());
        st.push(arr[i]);
    }

    return mins;
}

int main(){
    int arr[] = {8,2,9,2,7,4,7,3,9,8,4,6};
    int n = sizeof(arr)/sizeof(int);

    auto v = rightMins(arr,n);
    for(auto element : v)
        cout<<element<<" ";

    return 0;
}
