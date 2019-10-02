#include <iostream>
#include <cstdio>

using namespace std;

int s[23],a[23],v[23],n,k,d,x,i,j,nr,t;
int bun(long mask)
{
    return !mask;
}

void back(int x,int mask)
{
    if(k==x-1)
     {   if(bun(mask))
         {   for (int i=1;i<=k;i++) printf("%d ",v[i]);
             for (int i=1;i<=d;i++) a[i]=0;
             printf("\n");
         }
     }
     else
         for(int i=v[x-1]+1;i<=n;i++)
         {   v[x]=i;
             back(x+1,mask&s[i]);
             // for (i=1;i<=n;i++)
         }
}

int main()
{
    freopen("pluricex.in","r",stdin);
    freopen("pluricex.out","w",stdout);
    scanf("%ld%ld%ld",&n,&k,&d);
    for (i=1;i<=n;i++)
    {
        scanf("%ld",&nr);
        s[i] = (1<<d)-1;
        for (j=1;j<=nr;j++) {scanf("%ld",&t); s[i]^=1<<(t-1);}
    }
    back(1,(1<<d)-1);
    return 0;
}
