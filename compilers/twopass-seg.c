// read http://www.lysator.liu.se/c/c-faq/c-faq-toc.html#c-2
// read c-faq.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 128
#define MAX_LINES TABLE_SIZE
#define LINE_SIZE 128

// GLobals
struct table {
    char *symbol;
    int location;
}st[TABLE_SIZE], ft[TABLE_SIZE];

char *pot[] = { "start", "using", "drop", "end", "dc", "ds", "equ"};
char *mot[] = { "stop", "add", "sub", "mult", "mover", "movem", "comp", "bc", "div", "read", "print"};
char *reg[] = { "areg", "breg", "creg"};
int lc = 0, line_count = 0;
int result[MAX_LINES] = {0}, flag[MAX_LINES], next_st_index = 0, next_ft_index = 0;


// Prototypes
void table_init(struct table tbl[]);
int checkTok(char *token, char *final[]);
int find_symbol(char *token, struct table[]);
void process_token(char *token, int first);


int main(int argc, char* argv[])
{
	FILE *fp, *fp2;
	char *path = argv[1];
    char *tempchar, *token;
    char line[LINE_SIZE], line_cpy[LINE_SIZE];
    char dlm[] = " ,'";
    int firstword, temp, i;
    fp = fopen(path, "r");
    fp2 = fp;

    for(i = 0; i < MAX_LINES; i++){
        flag[i] = -1;
    }

    table_init(st);
    table_init(ft);

    // First pass
	while(fgets(line, sizeof line, fp) != NULL){
		firstword = 1;

        token = strtok(line_cpy, dlm);
        do {
            printf("Processing: %s\n", line);
            strcpy(line_cpy, line);
            process_token(token, firstword);
            token = strtok(NULL, dlm);
            firstword = 0;
        } while(token != NULL);

        line_count++;
	}

    // Second pass
    line_count = 0;
    while (fgets(line, sizeof line, fp) != NULL) {
        if((temp = flag[line_count]) != -1){
            tempchar = ft[temp].symbol;
            temp = find_symbol(tempchar, st);
            result[line_count] += temp;
        }
        line_count++;
    }

    for(i = 0; i < line_count; i++){
        printf("+%.6d", result[i]);
    }
    return 0;
}

void table_init(struct table tbl[])
{
    int i;
    for(i = 0; i < TABLE_SIZE; i++){
        tbl[i].symbol = NULL;
        tbl[i].location = -1;
    }
}

int checkTok(char *token, char *final[])
{
	size_t i;
    for (i = 0; i < sizeof(final)/sizeof(final[0]); i++) {
        if(strcmp(token, final[i]) == 0){
            return i;
        }
    }
    return -1;
}

int find_symbol(char *token, struct table tbl[])
{
    int i;
    for(i = 0; i < TABLE_SIZE; i++){
        if(strcmp(token, tbl[i].symbol) == 0){
            return tbl[i].location;
        }
    }
    return -1;
}

void process_token(char *token, int first)
{
    int temp;

    if(checkTok(token, pot) != -1){
        // If a pseudo opcode, machine code has all 0's
        if(!first){
            printf("Found an invalid reference. %s should be the first value.", token);
        }
        result[line_count] = 0;
    } else if((temp = checkTok(token, mot)) != -1){
        // If a mnemonic opcode, machine code has it's opcode
        // [SIGN] [OPCODE] [REG LOC] [MEM LOC]
        // 1 bit  2 bits    1 bit     3 bits
        // Hence opcode is multiplied by 10000 (4 bit offset)
        if(!first){
            printf("Found an invalid reference. %s should be the first value.", token);
        }
        result[line_count] = temp * 10000;
    } else if((temp = checkTok(token, reg)) != -1){
        // If a register is encountered, machine code has reg location
        // location is multiplied by 1000 (3 bit offset)
        result[line_count] += (temp*1000);
    } else {
        // label is present
        // {{TODO}} check if find_symbol and firstword both are necessary or not
        if(first && (find_symbol(token, st) == -1)){
            // If firstword and not already present in sybmbol table
            // add it in symbol table with current lc
            strcpy(st[next_st_index++].symbol, token);
        } else {
            // If it's not the firstword.
            if((temp = find_symbol(token, st)) != -1){
                result[line_count] += temp;
            } else{
                if((temp = find_symbol(token, ft)) == -1){
                    // If it's not present in flag table
                    // add it to flag table
                    strcpy(st[next_ft_index].symbol, token);
                    st[next_ft_index].location = next_ft_index++;
                }
                flag[line_count] = find_symbol(token, ft);
            }
        }
    }
}
