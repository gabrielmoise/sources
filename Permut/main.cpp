#include <iostream>
#include <cstdio>

using namespace std;

long v[100005],x[100005],n,i;
long long s;

void quickv(long p_in, long p_sf)
{
    long a,b,mij,temp;
    a=p_in; b=p_sf;
    mij=v[(a+b)/2];
    do
    {
        while (v[a]<mij) a++;
        while (v[b]>mij) b--;
        if (a<=b)
        {
            temp=v[b];
            v[b]=v[a];
            v[a]=temp;
            a++;b--;
        }
    }
     while (b>=a);
    if (a<p_sf) quickv(a,p_sf);
    if (p_in<b) quickv(p_in,b);
}

void quickx(long p_in1, long p_sf1)
{
    long a1,b1,mij1,temp1;
    a1=p_in1; b1=p_sf1;
    mij1=x[(a1+b1)/2];
    do
    {
        while (x[a1]<mij1) a1++;
        while (x[b1]>mij1) b1--;
        if (a1<=b1)
        {
            temp1=x[b1];
            x[b1]=x[a1];
            x[a1]=temp1;
            a1++;b1--;
        }
    }
    while (b1>=a1);
    if (a1<p_sf1) quickx(a1,p_sf1);
    if (p_in1<b1) quickx(p_in1,b1);
}

int main()
{
    freopen("permut.in","r",stdin);
    freopen("permut.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) scanf("%ld",&v[i]);
    quickv(1,n);
    for (i=1;i<=n;i++) scanf("%ld",&x[i]);
    quickx(1,n);
    s=0;
    for (i=1;i<=n;i++) s=s+(v[i]*x[i]);
    printf("%lld",s);
    return 0;
}
