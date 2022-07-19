#include <iostream>
#include <map>
using namespace std;


bool isomorphic(string s, string t){
    map<char,char>  mp;
    map<char,bool> used;

    for(int i=0;i<s.size();i++){
        if(mp.find(s[i]) == mp.end()){
            if(used.find(t[i]) !=  used.end())
                return false;
             mp[s[i]] = t[i];
             used[t[i]] = true;
        }
        else{
          if(mp[s[i]] != t[i])
              return false;
        }
    }
    return true;
}

int main(){

    cout<<isomorphic("title","paper")<<endl;

    return 0;
}
