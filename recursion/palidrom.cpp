#include <iostream>
using namespace std;

bool isPalindrom(string str,int l,int r,int n){
    if(n < 2) 
        return true; 

    if(str[l] == str[r])
        return isPalindrom(str,l+1,r-1,n-2);

    return false;

}

int main(){
    if(isPalindrom("eracecar",0,7-1,7)){
        cout<<"ISPALINDROM!!!";
    }
    else  cout<<"NOT_PALINDROM";
    return 0;
}
