#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int i,j;
    char pass[4], word[5];
    fgets(pass, 5, stdin);
    FILE* fp;
    fp = fopen("/Users/ox/words.4", "r");
    // check pass for every word in dictionary < len-8
    while (fscanf(fp, "%s", word) != EOF) {
        if (strcmp(word, pass) == 0) {
            printf("Found the password:%s\n", word);
            return 1;
        }
    }
    printf("Dictionary did not work.. exiting");
    return 0;
}
/*
ox ~/Dropbox/Projects/school/crypto master* $ gcc pwdcrack.c
ox ~/Dropbox/Projects/school/crypto master* $ ./a.out
zoom
Found the password:zoom
ox ~/Dropbox/Projects/school/crypto master* $ ./a.out
abcd
Dictionary did not work.. exiting%
*/
