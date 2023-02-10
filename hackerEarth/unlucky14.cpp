#include <iostream>
using namespace std;


int solve(int n){
    if(n==0)
        return 0;

    int number_of_strings = 1;
    for(int i=0;i<n;i++){
        number_of_strings*= 10;
    }

    return number_of_strings - (n-1);
}


int main(int argc,char **args){
    string s(1,*(*(args+1)));
    int n = stoi(s);
    cout<<solve(n);

    return 0;
}
