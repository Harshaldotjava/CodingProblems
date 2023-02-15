#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int reverseNumber(int n){
    int reversed_number = 0;

    while(n != 0){
        int last_digit = n % 10;
        reversed_number = (reversed_number * 10) + last_digit;
        n /= 10;
    }
    return reversed_number;
}

vector<int> convertToBinary(int n){
    vector<int> binary;
    while(n!=0){
        binary.push_back(n % 2);
        n = n/2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}



bool isBinaryPalindrom(int n){
     vector<int> binary = convertToBinary(n);
     vector<int> reverse_binary = binary;

     reverse(reverse_binary.begin(),reverse_binary.end());
     if(binary == reverse_binary)
        return true;
   
    return false;
}

int operation(int n){
    if(isBinaryPalindrom(n) || n == 0)
        return 0;
    return 1 + operation(n-1);
}

int main(int argc,char **aargv){

    cout<<operation(7);
    cout<<endl;
}
