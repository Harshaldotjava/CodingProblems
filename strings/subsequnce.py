def isSubSequence(s,t):
	spointer = 0
	
	for i in range(len(t)):
		if(spointer == len(s)):
			return True
		if(s[spointer] == t[i]):
			spointer += 1
			
	if(spointer == len(s)):
		return True
	return False
	
	
print(isSubSequence("har","kwjsvsnllbalr"))
			
			