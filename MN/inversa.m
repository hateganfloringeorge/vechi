function [A] = inversa(X)
%algoritmul Grand-Schmidt pentru QR
[m n] = size(X);
	Q = zeros(m,n);
	R = zeros(n);
	
	for j = 1 : n
		for i = 1 : j-1
			R(i,j) = Q(:,i)' * X(:,j);
		endfor
		
		s = zeros(m,1);
		
		s = Q(:, 1:j-1) * R(1:j-1, j);
		
		aux = X(:,j) - s;		
		
		R(j,j) = norm(aux,2);
		Q(:,j) = aux/R(j,j);
	endfor

[n,n] = size(R);
	%inversare matricei superior triunghiulata
for i = n:-1:1
	Ri(i,i)=1/R(i,i);
	for j=i-1:-1:1
		Ri(j,i)=-R(j,j+1:i)*Ri(j+1:i,i)/R(j,j);
	endfor
	endfor
	% inlocuid pe A^-1 cu (QR)^-1 obtinem A^-1 = R^-1 * Q' 	
A=Ri*Q';	
		 
