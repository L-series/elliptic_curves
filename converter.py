import re

with open("prime_all_00417","r") as f:
	lines = f.readlines()
	count = 0
	for line in lines:
		arr = eval(line)
#        ar1 = [0, 0, 0, −10012, 346900]	
        	
		a1 = arr[1][0]
		a2 = arr[1][1]
		a3 = arr[1][2]
		a4 = arr[1][3]
		a6 = arr[1][4]
		#print(a1)
		#print(a2)
		b2 = a1**2+4*a2
		b4 = a1*a3 + 2*a4
		b6 = a3**2 + 4*a6
		v1 = (b2,b4,b6)
		#print(v1)
		mb2 = b2 % 8
		mb4 = b4 % 8
		mb6 = b6 % 8
		
		v = (mb2,mb4,mb6)
		#print(v)
		
		if (v == (1,1,1) or  v == (1,3,1) or v == (5,2,4) or  v==(0,2,1) or  v == (0,0,0) or v == (4,0,1)):
			print(v)
			count +=1


			print(count)
        
		
