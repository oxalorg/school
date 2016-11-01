#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // n - block size
    // m - no of addresses
    int n, m;
    int x;
    int block, temp, temp2, temp3, offset, offset2, offset3;
    scanf("%d %d\n", &n, &m);
    scanf("%d", &x);

    if (x < 10*n){
        // 10 direct blocks
        temp = x/n;
        block = temp;
        offset = x - temp*n;
        printf("Direct Block: %d, Offset: %d\n", block, offset);
    } else if( x < 10*n + m*n) { 
        // 1 Single Indirect
        x = x - 10*n;
        temp = x/n;
        block = temp;
        offset = x - temp*n;
        printf("SingleIndirect 1 --> %d Offset: %d\n", block, offset);
    } else if (x < 10*n + m*n + m*m*n) {
        // 1 Double Indirect
        x = x - 10*n - m*n;
        temp = x/(m*n);
        offset = x - temp*m*n;
        temp2 = offset/n;
        offset2 = offset - temp2*n;
        printf("DoubleIndirect 1 --> Level 1: %d, Level 2: %d, Offset: %d\n", temp, temp2, offset2);
    } else if (x < 10*n + m*n + m*m*n + m*m*m*n){
        // 1 Triple Indirect
        x = x - 10*n - m*n - m*m*n;
        temp = x/(m*m*n);
        offset = x - temp*m*m*n;
        temp2 = offset/m*n;
        offset2 = offset - temp2*m*n;
        temp3 = offset2/n;
        offset3 = offset2 - temp3*n;
        printf("TripleIndirect 1 --> Level 1: %d, Level 2: %d, Level 3: %d, Offset: %d\n", temp, temp2, temp3, offset3);
    } else {
        printf("Invalid.\n");
    }
    return 0;
}