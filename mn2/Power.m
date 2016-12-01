function R2 = Power(nume, d, eps)
[a] = textread(nume, "%f");
N = a(1,1);
A = zeros(N);
z = 3;
one = ones(N,1);
K = zeros(N);
for i = 1 : N
	k = a(z,1);  
	for j = 1 : k
	A(i ,a(z+1, 1) )++;
	z++;
	endfor
z += 2 ;
A(i,i) = 0;
endfor
for i = 1 : N
	K(i,i) = 1 / sum(A(i,:));
	endfor
M = (K * A)';
R1 = ones(N,1) /N;
R2 = (d*M + (1-d)/ N* one)*R1;
while( norm (R2-R1) > eps)
R1 = R2;
R2 = (d*M + (1-d)/N*one)*R2;
end