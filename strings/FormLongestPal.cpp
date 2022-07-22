#include <iostream>
#include <map>
using namespace std;

int longPalLen(string s){
    map<char,int> mp;
    int ans = 0;
    for(auto ch : s)
        mp[ch]++;

    bool isOdd = false;
    for(auto pair : mp){
        if(pair.second %2 == 0)
            ans += pair.second;
        else{
            isOdd = true;
            ans += pair.second - 1;
        }
   }
   if(isOdd)
       return ans +1;
   return ans;
}


int main(){}
