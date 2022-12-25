#include <iostream>
using namespace std;


int main(){
    int  t;
    cin>>t;

    while(t--){
        int cost_of_green_ballons;
        int cost_of_purple_ballons;
        cin>>cost_of_green_ballons;
        cin>>cost_of_purple_ballons;
        int mincost = min(cost_of_green_ballons,cost_of_purple_ballons);
        int maxcost = max(cost_of_green_ballons,cost_of_purple_ballons);
        int n;
        cin>>n;
        int table[n][2]; 
        int cost = 0;
        for(int i=0;i<n;i++){
            int p1; cin>>p1;
            int p2; cin>>p2;
            if(p1 == 0 && p2 == 0)
                continue;
            else if(p1 & p2)
                cost += mincost + maxcost; 
            else
                cost += mincost;
        }
        cout<<cost<<endl;
    }
    return 0;
}
