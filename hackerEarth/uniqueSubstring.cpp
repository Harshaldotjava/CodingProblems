#include <iostream>
#include <deque>
#include <set>

using namespace std;

int solve(string str,int n){
    deque<char> dq;
    set<char> s;
    int count = 0;

    for(int i=0;i<n;i++){
        if(s.find(str[i]) != s.end()){
            dq.push_back('#');
            count++;
        }
        else{
            dq.push_back(str[i]);
            s.insert(str[i]);
        }

        if(dq.size() > 2){
            if(s.find(*dq.begin()) != s.end()){
                s.erase(*dq.begin());
            }
        }
    }
    return count;
}

int main(int argsc,char **args){
    cout<<solve("aaaba",5)<<endl;     
}
