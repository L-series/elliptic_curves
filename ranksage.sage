import re

with open("medcond.txt","r") as f:
	lines = f.readlines()


	for line in lines:
		arr = eval(line)
		
		a1 = arr[1][0]
		a2 = arr[1][1]
		a3 = arr[1][2]
		a4 = arr[1][3]
		a6 = arr[1][4]
		b2 = a1^2+4*a2
		b4 = a1*a3 + 2*a4
		b6 = a3^2 + 4*a6

		mb2 = b2 % 8
		mb4 = b4 % 8
		mb6 = b6 % 8
		v = (mb2,mb4,mb6)
		if (v == (1,1,1) || v == (1,3,1) || v == (5,2,4) || v==(0,2,1) || v == (0,0,0) || v == (4,0,1))
			print(v)

		
