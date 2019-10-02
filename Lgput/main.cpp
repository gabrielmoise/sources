#include <iostream>
#include <cstdio>

const int m=1999999973;
long i,n,p;
long long a,sol;

int main()
{

    freopen("lgput.in","r",stdin);
    freopen("lgput.out","w",stdout);
    scanf("%ld%ld",&n,&p);
    a=n; sol=1;
    for (i=0;(1<<i)<=p;i++)
    {
        if (((1<<i)&p)>0)
            sol=(sol*a)%m;
            a=(a*a)%m;
    }
    printf("%lld\n",sol);
    return 0;
}
