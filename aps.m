
for x in [0..9] do
	str := "/run/media/eva/BACKUP/primefiles/pf/prime_all_0000" cat Sprint(x);
	file:=Read(str);
	sp := Split(file,"\n");
	SetClassGroupBounds("GRH");
	
	out:= "aps" cat "Sprint(x)" cat ".txt";
	for i in sp do 


		//Shitty approx to Sha

		a,b,c :=Regexp("([0-9-]+)\,\\[([0-9-]+)\,([0-9-]+)\,([0-9-]+)\,([0-9-\]+)\,([0-9-]+)\\]\,([0-9-]+)\\]",i);         
		E:= EllipticCurve([StringToInteger(c[2]),StringToInteger(c[3]),StringToInteger(c[4]),StringToInteger(c[5]),StringToInteger(c[6])]); 
		t:=TracesOfFrobenius(E,100);
		Write(out,Sprint(t));

	end for;
end for;
