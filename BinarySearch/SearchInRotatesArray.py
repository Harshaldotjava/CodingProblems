
def findRotationPoint(arr):
	low = 0
	high = len(arr) - 1
	
	while(low <= high):
		mid = (low + high)//2
		if(mid > 1 and arr[mid-1] > arr[mid]):
			return mid -1
		
		if(mid < len(arr)-1 and arr[mid+1] < arr[mid]):
			return mid
		
		if(arr[low] < arr[mid]):
			low = mid+1
		else:
			high = mid-1
	
	return -1
	
	
def binarySearch(arr,low,high,key):
	
	while(low <= high):
		mid = (low + high)//2
		if(arr[mid] == key):
			return mid
		if(arr[mid] < key):
			low = mid + 1
		else:
			high = mid-1
		
	return -1
	
def searchInRotated(arr,n,key):
	point = findRotationPoint(arr)
	
	right = binarySearch(arr,point,n-1,key)
	left = binarySearch(arr,0,point+1,key)
	
	if(right > -1):
		return right
	if(left > -1):
		return left
	return -1
	
	
arr = [6, 7, 8, 9, 10, 1, 2, 3,4]

index = searchInRotated(arr,9,3)

print(index)
	


	