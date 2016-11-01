/*Round Robin Scheduling Algorithm C Program*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int st[10], bt[10], wt[10], tat[10], n, z, l;
    int i, count=0; //swt=0, stat=0, sq=0;
    float awt=0.0, atat=0.0, temp, tq ;
    float swt = 0.0, stat = 0.0, sq = 0.0;
    //printf("enter number of processes : ");
    //scanf("%d", &n);
    //printf("\n enter burst time for processes ");
    n = 10;
    srand(time(NULL));
    for(i=0; i<n;i++)
    {
        bt[i] = 10 + (rand() % 30);
        st[i]=bt[i];
    }
    //printf("\n enter time quantum : ");
    //scanf("%d", &tq);
    tq = 0;
    for(z = 0; z < 100; z++){
        tq += 0.1;
        for(l = 0; l < n; l++){
            st[l] = bt[l];
            tat[l] = 0;
            wt[l] = 0;

        }
        while(1)
        {
            for(i=0, count=0;i<n;i++)
            {
                temp=tq;
                if(st[i]==0)
                {
                    count++;
                    continue;
                }
                if(st[i]>tq)
                {
                    st[i]=st[i]-tq;
                }
                else
                    if (st[i]>=0)
                    {
                        temp=st[i];
                        st[i]=0;
                    }
                sq=sq+temp;
                tat[i]=sq;
            }
            if(n==count)
                break;
        }
        for(i=0;i<n;i++)
        {
            wt[i]=tat[i]-bt[i];
            swt=swt+wt[i];
            stat=stat+tat[i];
        }
        awt=(float)swt/n;
        atat=(float)stat/n;
        //printf(" \n process_no\t burst_time\t wait_time\t turn_around_time");
        //for(i=0; i<n; i++)
        //{
        //    printf("\n%d\t\t %d\t\t %d\t\t %d",i+1,bt[i],wt[i],tat[i]);
        //}
        //printf("\n average wait time is %f\naverage turn_around_time is %f\n",awt,atat);
        printf("%f,%f\n", tq, atat);
        swt = 0;
        stat = 0;
        sq = 0;

    }
    return 0;
}
