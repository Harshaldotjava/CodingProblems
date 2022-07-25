#include <iostream>

int badVersion = 7;

bool isBadVersion(int version){
	return (version == badVersion);	
}

int firstBadVersion(int n){
	int low = 0;
	int high = n;
	int res;
	while(low<=high){
		int mid = low + ((high-low)/2);
		if(isBadVersion(mid)){
			res = mid;
			high = mid-1;
		}
		else
		  low = mid+1;
	}
	return res;
}


int main(int argc, char *argv[])
{
	
}