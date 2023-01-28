#include <iostream>
using namespace std;

int Employee_rating(int days,int workload[]){
    int final_rating = 0;
    int rating = 0;

    for(int i=0;i<days;i++){
        if(workload[i]>6){
            rating++;
            final_rating = max(final_rating,rating);
        }
        else
            rating = 0;
    }
    return final_rating;
}

int main(){
   int arr[] = {3, 7, 8, 12, 4, 9, 8}; 
    cout<<Employee_rating(7,arr)<<endl;
}
