#include <stdlib.h>
#include <stdio.h>
#define P 10    // Number of Process
#define R 5     // Number of Resources

int main()
{
    int p, r, avail[R], max[P][R], alloc[P][R], need[P][R], marked[P];
    int i, j, z, count = 0, temp;
    // printf("Enter No of Process Resources\n");
    scanf("%d %d", &p, &r);

    // printf("Enter available:\n" );
    for (i = 0; i < r; ++i)
    {
        scanf("%d", &avail[i]);
    }

    // printf("Enter max matrix:\n");
    for (i = 0; i < p; ++i)
    {
        for (j = 0; j < r; ++j)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // printf("Enter alloc matrix:\n");
    for (i = 0; i < p; ++i)
    {
        marked[i] = 0;
        for (j = 0; j < r; ++j)
        {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    i = 0;
    z = 0;
    // printf("Sequence: ");
    while(z++ < p)
    {
        for (i = 0; i < p; ++i)
        {
            if(!marked[i])
            {
                temp = 0;
                for (j = 0; j < r; ++j)
                {
                    if (need[i][j] <= avail[j])
                    {
                        temp++;
                    }
                }
                if(temp == r)
                {
                    for (j = 0; j < r; ++j)
                    {
                        avail[j] += alloc[i][j];
                    }
                    printf("%d", i);
                    marked[i] = 1;
                    count++;
                    break;
                }
            }
        }
    }
    if (count == p)
    {
        printf("\nThe above sequence is the Safe sequence.");
    } else {
        printf("\nSafe sequence can not be determined.");
    }
    return 0;
}