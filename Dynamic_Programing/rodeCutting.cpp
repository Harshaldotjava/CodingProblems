#include <iostream>
using namespace std;

int maxProfit(int length[],int prices[],int n,int size){
    if(n == 0 || size == 0){
        return 0;
    }

    if(length[n-1] <= size){
        return max(prices[n-1] + maxProfit(length,prices,n,size-length[n-1]),
                   maxProfit(length,prices,n-1,size)); 
    }
    else return maxProfit(length,prices,n-1,size);
}


int memoize(int length[],int prices[],int n,int size){
    int t[n+1][size+1];
    memset(t,0,sizeof(t));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<size+1;j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else if(length[i-1] <= j){
                t[i][j] = max(prices[i-1] + t[i][j-length[i-1]],
                          t[i-1][j]);
            }
            else t[i][j] = t[i-1][j];
        }
    }
    return t[n][size];
}


int main(){
    int len[] = {1,2,3,4,5,6,7,8};
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<memoize(len,prices,8,8);
    return 0;
}
