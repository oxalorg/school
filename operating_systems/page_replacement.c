#include <stdlib.h>
#include <stdio.h>
#define N 5
#define P 3

int main(int argc, char const *argv[])
{
    int a[N], b[P], counter = 0, page_hit = 0, page_fault = 0, flag, i, j;
    for ( i = 0; i < N; ++i)
    {
        scanf("%d", &a[i]);
    }
    for ( i = 0; i < P; ++i)
    {
        b[i] = -1;
    }
    for ( i = 0; i < N; ++i)
    {
        flag = 1;
        for ( j = 0; j < P; ++j)
        {
            if (a[i] == b[j])
            {
                page_hit++;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            page_fault++;
            b[counter] = a[i];
            counter = (counter + 1) % P;
        }
        // printf("%d %d %d %d\n", a[i], b[0], b[1], b[2]);
    }
    printf ("Total Pages: %d\n"
            "Page Faults: %d\n"
            "Page Hits: %d\n", N, page_fault, page_hit );

    return 0;
}
