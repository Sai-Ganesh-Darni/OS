#include<stdio.h>
int Q[100];
int f=-1,r=-1;

void enque(int k)
{
    if(f==-1 && r==-1){
        f++;
        r++;
    }
    else if(r==100)
    {
        printf("OVERFLOW");
    }
    Q[r++] = k;
}

int deque()
{
    if(f>r || f==-1)
    {
        printf("UNDERFLOW");
    }
    else{
        return Q[f++];
    }
}

void display()
{
    for(int i=f;i<r;i++)
    {
        printf("%d\n",Q[i]);
    }
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = *x;
}

void rr(int n,int p[],int at[],int bt[],int q)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(at[j]>at[j+1]){
                swap(&p[j+1],&p[j]);
                swap(&at[j+1],&at[j]);
                swap(&bt[j+1],&bt[j]);
            }
            else if(at[j]==at[j+1]){
                if(p[j]>p[j+1]){
                    swap(&p[j+1],&p[j]);
                    swap(&at[j+1],&at[j]);
                    swap(&bt[j+1],&bt[j]);
                }
            }
        }
    }
    int v[n],rbt[n];
    for(int i=0;i<n;i++){
        v[i]=-1;
        rbt[i]=bt[i];
    }
    int GC[100],ts[100],tc=0,gcc=0,t=0,k;
    ts[tc++] = t;
    for(int i=0;i<n;)
    {
        for(int j=0;j<n;j++)   
        {
            if(at[j]<=t && v[j]==-1){
                enque(j);
                v[j]=1;
            }
        }
        int fl = 0;
        if(f>r || f==-1){
            fl = 1;
        }
        if(fl==1)
        {
            GC[gcc++] = -1;
            t++;
            ts[tc++] = t;
        }
        else{
            k=deque();
            //printf("%d",k);
            GC[gcc++] = p[k];
            if(rbt[k]<=q){
                t+=rbt[k];
                rbt[k] = 0;
                // GC[gcc++] = p[k];
                ts[tc++] = t;
                i++;
            }
            else{
                rbt[k]-=q;
                t+=q;
                // GC[gcc++]=p[k];
                ts[tc++] = t;
                for(int j=0;j<n;j++)
                {
                    if(at[j]<=t && v[j]==-1){
                        enque(j);
                        v[j] = 1;
                    }
                }
                enque(k);
            }
        }

    }
    // for(int i=0;i<tc;i++){
    //     printf("%d\t",ts[i]);
    // }
    printf("\n");
    for(int i=0;i<gcc;i++){
        printf("%d\t",GC[i]);
    }

}

void main()
{
    int n=4;
    int p[] = {1,2,3,4};
    int at[] = {0,3,7,11};
    int bt[] = {2,2,3,2};
    int q = 2;
    rr(n,p, at, bt, q);
}
