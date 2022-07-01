
def merge(arr,start,mid,end):
	
		left = arr[start:mid+1]
		right = arr[mid+1:end]
		i = 0
		j = 0
		k = start
		while(i<len(left) and j < len(right)):
	
			if(left[i]  < right[j]):
				arr[k] = left[i]
				i = i+1
			else:
				arr[k] = right[j]
				j = j+1
			k = k+1
				
		while(i < len(left)):
			arr[k] = left[i]
			k = k+1
			i = i+1
		while(j < len(right)):
				arr[k] = right[j]
				k = k+1
				j = j+1


def mergeSort(arr,s,e):

	if(s < e):
		mid = (s+e)//2
		mergeSort(arr,s,mid)
		mergeSort(arr,mid+1,e)
		merge(arr,s,mid,e)
		
		
arr = [3,2,-100,1,-1,4]
arrSize = len(arr)
mid = arrSize//2
print(arr[0:1])

mergeSort(arr,0,arrSize)

print(arr)
