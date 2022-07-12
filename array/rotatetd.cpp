#include<iostream>
#include<vector>
using namespace std;


int fun(vector<vector<int>>& matrix,int m,int n){
    int space = matrix[0][0];
	
	for(int i = 1; i<n; i++){
        int temp = matrix[0][i];
        matrix[0][i] = space;
        space = temp;
    }

    for(int i = 1; i<m; i++){
        int temp = matrix[i][m-1];
        matrix[i][m-1] = space;
        space = temp;
    }
    for(int i = n-2; i>=0; i--){
        int temp = matrix[m-1][i];
        matrix[m-1][i] = space;
        space = temp;
    }

    for(int i = m-2; i>=0; i--){
        int temp = matrix[i][0];
        matrix[i][0] = space;
        space = temp;
    }
    return 0;
}

int main(){
	vector<vector<int>> v;
    v = {
        {1,2,3},
        {4,5,5},
        {7,8,9}
    };
	int ans = fun(v,3,3);
    for(auto vec : v){
        for(auto i : vec)
            cout<<i<<"  ";
        cout<<endl;
    };
    return 0;
}
