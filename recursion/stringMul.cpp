#include <iostream>
#include <vector>
using namespace std;

vector<string> solve(string s1,string s2){

    if(s1.length() == 0){
        vector<string> s;
        return s;
    }

    char ch = *(s1.end()-1);
    s1.erase(s1.end()-1);
    vector<string> v = solve(s1,s2);

    for(int i=0;i<s2.length();i++)   
        v.push_back(string(1,ch) + string(1,s2[i]));
    
    return v;
}


int main(){
    string s1 = "abcd";
    string s2 = "1234";
    vector<string> v  =  solve(s1,s2);
    for(auto i : v ){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}





