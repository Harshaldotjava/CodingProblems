def isIsomorphic(s,t):
	char = {}
	used = set()

	for i in range(len(s)):
	
		if(s[i] not in char):

			if(t[i] in used):
				return False
			char[s[i]] = t[i]
			used.add(t[i])
		else:
			if(char[s[i]] != t[i]):
				return False
				
	return True
	
		
			
if(isIsomorphic("foo","ejg")):
	print("yes")
else:
	print("no")	
		

			
				