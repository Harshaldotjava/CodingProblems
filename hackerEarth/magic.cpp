#include <iostream>
using namespace std;

int solve(int x,int l,int n){
    int min_erase = -1;
    int max_erase = x;

    while( max_erase - min_erase > 1){
        int erase = max_erase + min_erase;
        int cur_x = x - erase;

        bool can_pass = true;
        for(int i=0;i<n;i++){
            if(cur_x > l)
                can_pass = false;
            cur_x *=2;
        }
        if(can_pass){
            max_erase = erase;
        }
        else min_erase = erase;
    }

    return max_erase;
}

int main(){
   
    return 0;
}
