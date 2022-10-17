#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[],int n,int k){
   priority_queue<int,vector<int>,greater<int>> que;

   for(int i=0;i<n;i++){
      if(que.size() > k)
	que.pop();
      que.push(arr[i]);
   }

   return que.top();

}

int main(){
   int arr[] = {1,2,3,4,5,6};
   int n = sizeof(arr)/sizeof(*arr);
   int k = 3;
   cout<< kthSmallest(arr,n,k);
   cout<<endl;
}
