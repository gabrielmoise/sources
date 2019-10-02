#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

bitset <1000005> v;
long prim[20000];
long long i,n,t,q,j,nrdiv,sdiv,k,p,d;

long long pow(long long x,long long y)
{
    long long a,sol,i;
    a=x; sol=1;
    for (i=0;(1<<i)<=y;i++) {if (((1<<i)&y)>0) sol=sol*a; a=a*a;}
    return (sol);
}

int main()
{
    freopen("ssnd.in","r",stdin);
    freopen("ssnd.out","w",stdout);
    //CIUR
    i=2; n=20;
    while (i<=n) {i=i+2; v[i]=1;}
    i=3;
    while (i<=n) if (v[i]!=1)
    {
        j=i*2;
        while (j<=n) {v[j]=1; j=j+i;}
        i=i+2;
    }
    else {i=i+2;}
    v[1]=1; v[0]=1;
    k=0;
    for (i=2;i<=n;i++) if (v[i]==0) {k++; prim[k]=i;}
    scanf("%lld",&t);
    for (q=1;q<=t;q++)
    {
        scanf("%lld",&n);
        i=1; k=0; nrdiv=1; sdiv=1;
        while (n!=1)
        {
            if (prim[i]!=0) if (n%prim[i]==0) k++;
            if (prim[i]>0) while (n%prim[i]==0) {d++; n=n/prim[i];}
            if (d>0) p=prim[i];
            nrdiv=nrdiv*(d+1);
            if (p>1) sdiv=sdiv*((pow(p,d+1)-1)/(p-1));
            p=0; d=0;
            i++;
        }
        printf("%lld %lld\n",nrdiv,sdiv);
    }
    return 0;
}
