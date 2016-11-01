/**
 * Symbol and Literal Table
 * @MiteshNinja 15/04/16
**/

#include <stdio.h>
#include <string.h>

int line_count = 0, col = 0;
int templc = 0, lc = 0;

struct stable{
    char symbol[10];
    int value;
    int length;
} st[10];
int stlen = 0;

struct ltable{
    char literal[10];
    int value;
} lt[10];
int ltlen = 0;

void process_token(char *token){
    //printf("Token being processed: %s\n", token);
    if (strcmp(token, "$") == 0) {
        return;
    }
    if(col == 1){
        // Label
        strcpy(st[stlen].symbol, token);
        st[stlen].value = templc;
        st[stlen].length = 4;
        stlen++;
    } else if(col == 2){
        // Adjust LC based on MOT
        if(strcmp(token, "START") != 0 && strcmp(token, "END") != 0 ){
            // If token is not start or end
            lc = lc + 4;
        }
    } else if(col == 3){
        // No use
    } else {
        // Check for literal
	// LC value for literal is calculated after complete table is created.
        if(strncmp(token, "=F", strlen("=F")) == 0){
            strcpy(lt[ltlen].literal, token);
            ltlen++;
        }
    }
}

int main(int argc, char* argv[]){
    int i;
    char *path = argv[1];
    FILE *fp = fopen(path, "r");

    char dlm[] = " ,\n\t";
    char line[100], line_cpy[100];
    char *token;
    while(fgets(line, sizeof(line), fp) != NULL){
        col = 1;
        templc = lc;
        strcpy(line_cpy, line);
        token = strtok(line_cpy, dlm);
        do{
            process_token(token);
            token = strtok(NULL, dlm);
            col++;
        }while(token != NULL);
        line_count++;
    }

    printf("SYMBOL\tValue\tLength\n");
    for(i = 0; i < stlen; i++){
        printf("%s\t%d\t%d\n", st[i].symbol, st[i].value, st[i].length);
    }
    printf("-----------------------\n");
    printf("LITERAL\tValue\n");
    for(i = 0; i < ltlen; i++){
	lc = lc + 4;
	lt[i].value = lc; 
        printf("%s\t%d\n", lt[i].literal, lt[i].value);
    }
}

/*
Input file:
PRG     START
$       USING       *, 15
$       L           1,FOUR
$       A           1,=F'2'
FOUR    DC          F'4'
$       END

compilers❯ gcc symbol-literal.c && ./a.out /home/mitesh/Dropbox/Projects/school/compilers/in.txt
SYMBOL	Value	Length
PRG	0	    4
FOUR	12	    4
-----------------------
LITERAL	Value
=F'2'	20
*/
