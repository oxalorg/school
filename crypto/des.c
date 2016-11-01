#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct b64{
    int b[64] = {0};
}

struct b32{
    int b[32] = {0};
}

struct b48{
    int b[48] = {0};
}

struct b48 expand(struct b32 inb){
    struct b48 exp;
    int start, end;
    for(int i = 0; i < 8; i++){
        start = 6*i;
        end = 6*(i+1);
        for(int j = start, int k = 0; j < end; j++){
            if(j == start){
                exp.b[j] == inb.b[(k-1)%32];
            } else if (j == end-1){
                exp.b[j] == inb.b[(k+1)%32];
            } else {
                exp.b[j] == inb.b[k];
                k++;
            }
        }
    }
    return exp;
}

void test_expand(){
    struct b32 inb;
    struct b48 out = expand(inb);
    
}

struct b32 substitute(struct b48 inb){
    struct b32 sub;
    int start, end, sarr[6];
    int temp[4];
    for(int i = 0; i < 8; i++){
        start = 6*i;
        end = 6*(i+1);
        for(int j = start; j < end; j++){
            sarr[j%6] = inb.b[j];
        }
        sbox(sarr, temp);
        start = 4*i;
        end = 4*(i+1);
        for(int j = start; j < end; j++){
            sub.b[j] = temp[j%4];
        }
    }
    return sub;
}

struct b32 func(struct b32 r1, struct b48 k1){
    struct b48 exp = expand(r1);
}
