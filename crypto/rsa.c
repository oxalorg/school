#include<stdio.h>

long pow2(int x, int p){
	long a = 1;
	for(int i = 0; i < p; i++){
		a *= x;
	}
	return a;
}

long powmod(int x, int p, int n){
	long a = 1;
	for(int i = 0; i < p; i++){
		a *= x%n;
		a = a % n;
	}
	return a;
}

int gcd ( int a, int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}

int mmi(int b, int n){
	int r1 = n, r2 = b, t1 = 0, t2 = 1, q, r, t;
	while(r2 > 0){
		q = r1/r2;
		r = r1 - q *r2;
		r1 = r2;
		r2 = r;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	if(r1 == 1){
		if (t1 < 0)
			return t1+t2;
		else
			return t1;
	}
	return 0;
} 

int main(){
	int p, q, d;
	scanf("%d %d", &p, &q);
	long phi = (p-1) * (q-1);
	long n = p*q;
	int e = 1;
	while(e++){
		if(gcd(e, phi) == 1){
			d = mmi(e, phi);
			if(d != 0)	
				break;
		}
	}
	printf("Relative prime chosen: %d, inverse: %d\n", e, d);
	long m;
	printf("Enter message: ");
	scanf("%ld", &m);
	long c = ((int)(pow2(m, e)))%n;
	printf("Cipher is: %ld\n", c);
	printf("Decrypted txt is: %ld\n", (powmod(c,d,n)));
	return 0;	
}
ox ~/Dropbox/Projects/school/crypto master* $ ./a.out
123 12
Relative prime chosen: 3, inverse: 895
Enter message: 1234
Cipher is: 64
Decrypted txt is: 1234
