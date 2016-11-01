#include <stdlib.h>
#include <stdio.h>
#define N 5
#define P 3

void update_hit_counter(int j, int counter[P])
{
    // 0 - Least recently used
    // 1 - Recently used
    // 2 - Most recently used
    // counter[j] - Status of jth page frame
    int k;
    int temp = (j+1) % P;
    int temp2 = (j+2) % P;

    if (counter[j] == 0)
    {
        if(counter[temp] == 1){
            counter[temp] = 0;
            counter[temp2] = 1;
        } else {
            counter[temp] = 1;
            counter[temp2] = 0;
        }
        counter[j] = 2;
    } 
    else if (counter[j] == 1) 
    {
        if (counter[temp] == 2)
        {
            counter[temp] = 1;
        }
        else
        {
            counter[temp2] = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[N], b[P], page_hit = 0, page_fault = 0, flag, i, j;
    int counter[] = {-1, -1, -1};
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
                update_hit_counter(j, counter);
                page_hit++;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            page_fault++;
            least_recently_used = find_lru(counter);
            b[least_recently_used] = a[i];
            counter = (counter + 1) % P;
        }
        // printf("%d %d %d %d\n", a[i], b[0], b[1], b[2]);
    }
    printf ("Total Pages: %d\n"
            "Page Faults: %d\n"
            "Page Hits: %d\n", N, page_fault, page_hit );

    return 0;
}
