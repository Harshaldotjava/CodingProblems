#include <iostream>
#include <stdlib.h>
#include "histogram.h"
using namespace std;

int matrixArea(int matrix[][5],int n,int k){
    int maxArea = 0;
    int histo[k];
    memset(histo,0,sizeof(histo));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(matrix[i][j] == 0)
                histo[j] = 0;
            else
                histo[j] += matrix[i][j];
        }

        int area = maxAreaHistogram(histo,k);
        maxArea = max(area,maxArea);

    }

    return maxArea;
}

int main(){
    int matrix[4][5] = {{1,0,1,0,0},
                    {1,0,1,1,1},
                    {1,1,1,1,1},
                    {1,0,0,1,0}};
    int n = 4,k = 5;
    cout<< matrixArea(matrix,n,k)<<endl;
	return 0;
}
