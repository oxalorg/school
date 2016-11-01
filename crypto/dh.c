#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

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

int main(){
	int p, q, d;
	int a[1000];
	scanf("%d", &p);
    
    for(int i = 2; i < p; i++){
        if(p % i == 0){
            printf("%d is not a prime number. Try again.\n", p);
            return 1;
        }
    }

	int pr = 1, rep = 0;
	while(pr++){
		int i;
		for(i = 0; i < p-1; i++){
			a[i] = (int)powmod(pr, i, p);
			for(int j = 0; j < i; j++){
				if(a[j] == a[i]){
                    rep = i;
					i = p+1;
					break;
				}
			}
		}
		if(i < p){
			printf("Primitive root is: %d\n", pr);
			break;
		} else {
            printf("%d is not a primitive root. Repeats after: %d\n", pr, rep);
        }
	}

    srand(time(NULL));
	int x, y;
	x = rand() % p;
    y = rand() % p;
    printf("Alice has chosen: %d, whereas Bob has chosen: %d\n", x, y);
    int r1 = powmod(pr, x, p); // alice
    int r2 = powmod(pr, y, p); // bob

    printf("R1 by alice: %d. R2 by Bob: %d\n", r1, r2);
    // alice recieves r2
    int akey = powmod(r2, x, p);
    // bob recieves r1
    int bkey = powmod(r1, y, p);
    if (akey == bkey) {
        printf("Alice Key : %d, Bob Key: %d\n", akey, bkey);
        printf("Alice and Bob have reached a symmetric key aggrement.\n");
    } else {
        printf("Same key was not generated. Something went wrong.");
    }

	return 0;
}
ox ~/Dropbox/Projects/school/crypto master* $ ./a.out
11
Primitive root is: 2
Alice has chosen: 8, whereas Bob has chosen: 4
R1 by alice: 3. R2 by Bob: 5
Alice Key : 4, Bob Key: 4
Alice and Bob have reached a symmetric key aggrement.