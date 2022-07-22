#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices){
    int minStock = prices[0];
    int maxProfit = 0;

    for(auto buy : prices){
        if(buy < minStock)
            minStock = buy;
        int profit = buy - minStock;
        if(profit > maxProfit)
            maxProfit = profit;
    }
    return maxProfit;
}

int main(){

    vector<int> v = {7,1,5,3,6,4};
   cout<<maxProfit(v);

    return 0;
}
