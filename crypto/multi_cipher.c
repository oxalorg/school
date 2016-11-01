#include<stdio.h>

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
    int KEY = 3;
    char s[100], c[100], d[100];
    printf("\nEnter Key: ");
    scanf("%d ", &KEY);
    fgets(s, 100, stdin);
    printf("Encrypted text: ");
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] < 'z' && s[i] > 'a'){
            c[i] = (((s[i] - 'a') * KEY) % 26) + 'a';
            printf("%c", c[i]);
        } else {
            c[i] = s[i];
            printf("%c", s[i]);
        }
    }
    int KEY_INV = mmi(KEY, 26);
    printf("Decrypted text: ");
    for(int i = 0; c[i] != '\0'; i++){
        if(s[i] < 'z' && s[i] > 'a'){
            d[i] = (((c[i] - 'a') * KEY_INV) % 26) + 'a';
            printf("%c", d[i]);
        } else {
            d[i] = c[i];
            printf("%c", d[i]);
        }
    }
    return 1;
}

ox ~/Dropbox/Projects/school/crypto master* $ gcc -std=c99 multi_cipher.c
ox ~/Dropbox/Projects/school/crypto master* $ ./a.out

Enter Key: 3
hello world
Encrypted text: vmhhq oqzhj
Decrypted text: hello world
ox ~/Dropbox/Projects/school/crypto master* $