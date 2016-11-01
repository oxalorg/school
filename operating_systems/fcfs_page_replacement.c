#include <stdlib.h>
#include <stdio.h>
#define N 5
#define P 3

int main(int argc, char const *argv[])
{
    int a[N], b[P], counter = 0, page_hit = 0, page_fault = 0, flag, i, j;
    for ( i = 0; i < N; ++i)
    {
        // Page sequence
        scanf("%d", &a[i]);
    }
    for ( i = 0; i < P; ++i)
    {
        // Page frame buffers
        b[i] = -1;
    }

    // For every page
    for ( i = 0; i < N; ++i)
    {
        flag = 1;
        // Check each buffer
        for ( j = 0; j < P; ++j)
        {
            // If the page is present in the buffer
            if (a[i] == b[j])
            {
                // It's a page hit, move on to the next page
                page_hit++;
                flag = 0;
                break;
            }
        }
        // If page was not in an existing buffer
        if (flag)
        {
            // It's a page fault, replace the counter buffer with the page
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
