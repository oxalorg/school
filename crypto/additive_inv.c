#include <stdio.h>
#include <stdlib.h>
#define KEY 3

int main(){
    char s[100], c[100], d[100];
    fgets(s, 100, stdin);
    printf("Encrypted text: ");
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] < 'z' && s[i] > 'a'){
            c[i] = ((s[i] - 'a' + KEY) % 26) + 'a';
            printf("%c", c[i]);
        } else {
            c[i] = s[i];
            printf("%c", s[i]);
        }
    }
    printf("Decrypted text: ");
    for(int i = 0; c[i] != '\0'; i++){
        if(s[i] < 'z' && s[i] > 'a'){
            d[i] = ((c[i] - 'a' - KEY) % 26) + 'a';
            printf("%c", d[i]);
        } else {
            d[i] = c[i];
            printf("%c", d[i]);
        }
    }
    return 1;
}
ox ~/Dropbox/Projects/school/crypto master* $ gcc -std=c99 additive_inv.c
ox ~/Dropbox/Projects/school/crypto master* $ ./a.out
hello world
Encrypted text: khoor zruog
Decrypted text: hello world