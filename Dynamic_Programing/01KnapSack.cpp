#include <iostream>
using namespace std;

int max(int a, int b){
	return (a>b)?a:b;
}

int knap(int w,int wt[],int val[],int n){
	
	if(n == 0 || w == 0){
		return 0;
	}
	
	if(w >= wt[n-1]){
	  
		return max(
	    val[n-1] + knap(w-wt[n-1],wt,val,n-1),
		  knap(w-wt[n-1],wt,val,n-1) 
  
		  );            
	}
	return knap(w-wt[n-1],wt,val,n-1);

}

int knapsack(int w,int wt[],int val[],int n){
	int memo[w+1][n+1];
    memset(memo,0,sizeof(memo));
   
   for(int i=1;i<w+1;i++){
   	
   	for(int j=1;j<n+1;j++){
   		
   		if(i>=wt[j-1]){
 
   			memo[i][j] = max(
   				val[j-1] + memo[i-wt[j-1]][j-1],
   				memo[i][j-1]
   			);
   		
   		}
   		else{
   			memo[i][j] = memo[i][j-1];
   		}
        
   	}
   	
   }
   return memo[w][n];
}		

int main(int argc, char *argv[])
{
	int values[] = {1,2,3};
	int weight[] = {4,5,6};
	int n = 3;
	int w = 3;
	cout<<knapsack(w,weight,values,n);
}
