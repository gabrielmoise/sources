#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("stalpi3.in","r",stdin);
    freopen("stalpi3.out","w",stdout);
    scanf("%ld%ld",&n,&d);
    for (i=1;i<=n;i++)
    {
        scanf("%ld%ld",&x,&y);
        a[x]=y;
    }
    for (i=1;i<=n;i++)
    {
        scanf("%ld%ld",&x,&y);
        b[x]=y;
    }
    xa=0; xb=0; minim=20000;
    for (i=1;i<=30000;i++)
    {
        if ((xa[a[i]]==0) && (a[i]!=0)) xa[a[i]]=i;
        if ((xb[a[i]]==0) && (b[i]!=0)) xb[b[i]]=i;
        if (a[i]!=0) && (xb[i]!=0)

    }
}
