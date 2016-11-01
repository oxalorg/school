#include <stdio.h>
#define SET_LEN 2

struct set {
    int member;
    float value;
};

void equality(struct set a[], struct set b[]);

int main(){
    struct set a[SET_LEN] = {{1, 0.5}, {2, 0.7}};
    struct set b[SET_LEN] = {{1, 0.5}, {2, 0.7}};

    equality(a, b);

    return 1;
}

void equality(struct set a[SET_LEN], struct set b[SET_LEN]){
    for(int i = 0; i < SET_LEN; i++){
        printf("a: {%d, %f} b: {%d, %f}\n", a[i].member, a[i].value, b[i].member, b[i].value);
        if(a[i].member != b[i].member || a[i].value != b[i].value){
            printf("Not equal.\n");
            return;
        }
    }
    printf("Sets are equal.\n");
}
