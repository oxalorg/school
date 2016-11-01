#include <stdio.h>
#DEFINE LINE_SIZE 10

struct Prod{
    char l;
    char r[LINE_SIZE];
} p[10];

int main(int argc, char const *argv[]) {

    return 0;
}

void first(int prodNum){
    int lcounter;
    for(i = 0; i < PROD_SIZE; i++){
        
    }
}




void first(int i){
    char x = p[i].l;
    if (isNonTerminal(x)) {
        return x;
    } else if (isTerminal(x)) {
        if (first(p[i].r[0] == '@')) {
            return first();
        }
        return first(
    }
}
