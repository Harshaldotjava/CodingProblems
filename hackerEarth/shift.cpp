#include <iostream>
using namespace std;

string oneShift(string s){
    string result = "";
    for(int i=0;i<s.length();i++){
        result += s[(i + 1) % s.length()];
    }
    return result;
}

int solve(string s,int k){
    string maxStr = "";
    int found = 0;
    int shifts  = 0;
    for(int i=0;i<s.length();i++){
        if(s > max){
            maxStr = s;
        }
        s = oneShift(s);
    }


    while(true){
        if(maxStr == s)
            found++;

        if(found == k) break;
        s = oneShift(s);
        shifts++;

    }
    

    return shifts;
}

int solution2(string s,int k){
    string max = "";
    int d = 0;
    int p = -1;
    for(int i=0;i<s.length();i++){
        if(s > max){
            max = s;
        }
        else if (max == s){
            p = i - d;
        }
        s = oneShift(s);
    }
    return 0;
}


int main(){
    cout<<solution2("10101",2)<<endl;
    return 0;
}
