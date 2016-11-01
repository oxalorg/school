/**
 * First and Follow
 * @MiteshNinja 15/04/16
**/

#include <stdio.h>
#include <string.h>
char EPSILON = '^';
struct prod{
    char rhs[10];
    char lhs;
} rule[10];
int rulecount = 0;

int t = 0;

char term[20], nonterm[20];
int terminalcount = 0, nontermcount = 0;

int f[100][100] = {0};

void setFirst(char a, char b){
    int aval = a - '@';
    int bval = b - '@';
    f[a][b] = 1;
}

int getFirst(char a, char b){
    int aval = a - '@';
    int bval = b - '@';
    return f[a][b];
}

int isterm(char a){
    return (islower(a) || isdigit(a) || ispunct(a));
}

void printfirst(){
    int i, j;
    for(i = 0; i < nontermcount; ++i){
        printf("First of %c: {", nonterm[i]);
        for(j = 0; j < terminalcount; ++j){
            if (getFirst(nonterm[i], term[j])) {
                printf(" %c", term[j]);
            }
        }
        printf(" }\n");
    }
}

void first(){

    int change = 1, i, j, k;
    char symbol;
    while(change == 1){
        change = 0;
        for (i = 0; i < rulecount; i++) {
            for (j = 0; j < strlen(rule[i].rhs); j++) {

                symbol = rule[i].rhs[j];
                if(isterm(symbol) == 1){
                    if(getFirst(rule[i].lhs, symbol) != 1){
                        change = 1;
                    }
                    setFirst(rule[i].lhs, symbol);
                    break;
                } else{
                    for (k = 0; k < terminalcount; k++) {
                        if(getFirst(symbol, term[k]) == 1){
                            if(getFirst(rule[i].lhs, term[k]) != 1){
                                change = 1;
                            }
                            setFirst(rule[i].lhs, term[k]);
                        }
                    }
                    if(getFirst(symbol, EPSILON) == 0){
                        break;
                    } else {
                        int t22 = strlen(rule[i].rhs);
                        if(j == t22-1){
                            if(getFirst(rule[i].lhs, EPSILON) != 1){
                                change = 1;
                            }
                            setFirst(rule[i].lhs, EPSILON);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    char temp;
    int i, j;
    printf("Terminals\n");
    scanf("%s", term);
    printf("NonTerms\n");
    scanf("%s", nonterm);
    nontermcount = strlen(nonterm);
    terminalcount = strlen(term);

    printf("No of Rules\n");
    scanf("%d", &rulecount);
    for(i = 0; i < rulecount; ++i){
        scanf(" %c%s", &rule[i].lhs, rule[i].rhs);
    }
    first();
    for(i = 0; i < nontermcount; ++i){
        printf("First of %c: {", nonterm[i]);
        for(j = 0; j < terminalcount; ++j){
            if (getFirst(nonterm[i], term[j])) {
                printf(" %c", term[j]);
            }
        }
        if (getFirst(nonterm[i], EPSILON)){
            printf(" %c", EPSILON);
        }
        printf(" }\n");
    }

    return 0;
}
