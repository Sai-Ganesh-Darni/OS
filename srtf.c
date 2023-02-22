#include<stdio.h>
#include<limits.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int find(int n,int at[],int rbt[],int v[],int t)
{
    int min = INT_MAX,temp = -1;
    for(int i=0;i<n;i++)
    {
        if(at[i]<=t && min>=rbt[i] && v[i]==-1){
            if(rbt[i]==min){
                if(at[i]<at[temp]){
                    min = rbt[i];
                    temp=i;
                }
            }
            else{
                min = rbt[i];
                temp = i;
            }
        }
    }
    return temp;
}

int minI(int n,int at[],int t)
{
    int min = INT_MAX,temp;
    for(int i=0;i<n;i++)
    {
        if(at[i]>t && min>at[i]){
            min = at[i];
        }
    }
    return min;
}

void srtf(int n,int p[],int at[],int bt[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                swap(&p[j], &p[j + 1]);
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
            }
            else if (bt[j] == bt[j + 1])
            {
                if (at[j] > at[j + 1])
                {
                    swap(&p[j], &p[j + 1]);
                    swap(&at[j], &at[j + 1]);
                    swap(&bt[j], &bt[j + 1]);
                }
            }
        }
    }
    int v[n],rbt[n],ct[n],tat[n],wt[n];
    for(int i=0;i<n;i++)
    {
        v[i] = -1;
        rbt[i]= bt[i];
    }
    int t=0,GC[100],ts[100],tc=0,gcc=0;
    ts[tc++] = t;
    for(int i=0;i<n;)
    {
        int j = find(n,at,rbt,v,t);
        if(j==-1){
            GC[gcc++] = -1;
            t = minI(n,at,t);
            ts[tc++] = t;
        }
        else
        {
            int x = minI(n,at,t);
            if(x==INT_MAX){
                x = t+rbt[j];
            }
            if(rbt[j]<(x-t)){
                GC[gcc++] = p[j];
                t += rbt[j];
                rbt[j] = 0;
                ts[tc++] = t;
                v[j]=1;
                ct[j] = t;
                i++;
            }
            else{
                GC[gcc++] = p[j];
                rbt[j] = rbt[j]-(x-t);
                t = x;
                ts[tc++] = t;
                if(rbt[j]==0){
                    v[j] = 1;
                    ct[j] = t;
                    i++;
                }
            }

        }
    }
    printf("\n");
    for(int i=0;i<tc;i++){
        printf("%d ",ts[i]);
    }
    printf("\n");
    for(int i=0;i<gcc;i++){
        printf("%d ",GC[i]);
    }  
    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++)
        {
            if(p[j]>p[j+1]){
                swap(&p[j],&p[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&ct[j],&ct[j+1]);
                swap(&tat[j],&tat[j+1]);
                swap(&wt[j],&wt[j+1]);
            }
        }
    }
    printf("\nP  AT  BT  CT  TAT  WT\n");
    for(int i=0;i<n;i++){
        printf("%d  %d   %d   %d   %d   %d \n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }        

}

void main()
{
    // int n = 5;
    // int p[] = {1, 2, 3, 4, 5};
    // int ar[] = {5, 2, 1, 3, 4};
    // int bt[] = {2, 3, 4, 3, 2};
    int n = 3;
    int p[] = {1, 2, 3};
    int ar[] = {1, 6, 3};
    int bt[] = {1, 3, 2};
    srtf(n, p, ar, bt);
}
