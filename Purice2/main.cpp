#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long q,t,n,i,rez,a,b,rest,k;
long v[1000],x[1000],z[1000];

long cmmdc(long a, long b)
{
    rest=0;
    do
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    while (rest!=0);
    return a;
}

int main()
{
    freopen("purice2.in","r",stdin);
    freopen("purice2.out","w",stdout);
    scanf("%ld",&t);
    for (q=1;q<=t;q++)
    {
        scanf("%ld",&n);
        for (i=1;i<=n;i++) scanf("%ld",&v[i]);
        sort(v+1,v+n+1);
        v[n+1]=v[n]+1;
        for (i=1;i<=n;i++) if (v[i]!=v[i+1]) {k++; z[k]=v[i];}
        for (i=1;i<=k-1;i++) x[i]=z[i+1]-z[i];
        if (k>2) {i=3; rez=cmmdc(x[1],x[2]);
        while (i<=k)
        {
            rez=cmmdc(x[i],rez);
            i++;
            if (rez==1) break;
        }
        if (rez==1) printf("%ld\n",1);
            else printf("%ld\n",0);}
        else if (k==1) printf("%ld\n",0);
        else if (k==2) if (z[2]-z[1]==1) printf("%ld\n",1);
                                else printf("%ld\n",0);
        for (i=1;i<=100;i++) {z[i]=0; x[i]=0;}
        k=0;
    }
    return 0;
}
