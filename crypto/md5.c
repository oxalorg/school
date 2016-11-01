/*
 * MD5 simple implementation
 */
#include<stdio.h>
#include<math.h>
#define BLEN 512
#define MLEN 64

// Single 512 block of message
struct block
{
        int msg[512];
};

int main()
{
        struct block b;
        int temp = 0, mark;

        // scan input as 1's and 0's into an array
        for(int i = 0; i < 512; i++)
        {
                scanf("%d", &temp);
                if(temp == -1)
                {
                        mark = i;
                        break;
                }
        }

        printf("mark is %d\n", mark);
        // for i = mark to padding length put 1000....
        int padding = BLEN - MLEN - mark;
        b.msg[mark] = 1;
        for(int i = mark+1; i < BLEN-MLEN+48; i++)
        {
                b.msg[i] = 0;
        }

        printf("message length: \n");
        for(int i = BLEN-MLEN+48; i < BLEN; i++)
        {
                int p2 = (int)pow(2, BLEN - i);
//                printf("%d^%d = %d\n", 2, BLEN-i, p2);
//                printf("%d\n", mark);
                if(p2 < mark)
                {
                        b.msg[i] = 1;
                        mark = mark - p2;
                }
                else
                {
                        b.msg[i] = 0;
                }
                printf("%d", b.msg[i]);
        }

        long int = 0x

        return 1;
}
