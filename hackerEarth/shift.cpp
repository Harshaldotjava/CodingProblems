#include <iostream>
using namespace std;

string oneShift(string s){
    string result = "";
    for(int i=0;i<s.length();i++){
        result += s[(i + 1) % s.length()];
    }
    return result;
}

int solution2(string s,int k){
    string maxs = "";
    int shifts = 0;
    int p = -1;
    for(int i=0;i<s.length();i++){
        if(s > maxs){
            maxs = s;
            shifts = i;
        }
        else if (maxs == s){
            p = i - shifts+1;
        }
        s = oneShift(s);
    }
    if(p == -1){
        return shifts + s.length() * (k-1);
    }

    return shifts + s.length() * (k-1);
}


int main(){
    cout<<solution2("10101",2)<<endl;
    return 0;
}
