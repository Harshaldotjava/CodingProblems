#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;




vector<int> next_greater(vector<int> arr,int n){
    stack<pair<int,int>> st;
    vector<int> result;
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top().second <= arr[i])
            st.pop();

        if(st.empty())
            result.push_back(-1);
        else
            result.push_back(st.top().first);

        st.push({i,arr[i]});
    }

    reverse(result.begin(),result.end());
    return result;
}

vector<int> next_smallest(vector<int> arr,int n){
    stack<pair<int,int>> st;
    vector<int> result;


    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top().second >= arr[i])
            st.pop();

        if(st.empty())
            result.push_back(-1);
        else
            result.push_back(st.top().first);

        st.push({i,arr[i]});
            
    }

    reverse(result.begin(),result.end());
    return result;
}



vector<int> solve(vector<int> arr,int n){
    vector<int> ng = next_greater(arr,n);
    vector<int> ns = next_smallest(arr,n);

    vector<int> result;

    for(int i=0;i<n;i++){
        if(ng[i] != -1)
        result.push_back(arr[ns[i]]);
        else result.push_back(-1);
    }

    cout<<endl;
    return result;
}

void displayVector(vector<int> v){
    for(auto element : v)
        cout<<element<<"   ";    

    cout<<endl;
    return;
}

int main(){
    vector<int> arr = {3,7,1,7,8,4,5,2};
    vector<int> result = solve(arr,arr.size());
    displayVector(arr);
    displayVector(result); 

    return 0;
}
