#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

void cmmdc(long long a, long long b, long long &x, long long &y)
{
    if (b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        cmmdc(b,a%b,x,y);
        long long aux=x;
        x=y;
        y=aux-(a/b)*y;
    }
}

int main()
{
    long long A,N,x=0,y;
    freopen("inversmodular.in","r",stdin);
    freopen("inversmodular.out","w",stdout);
    scanf("%lld%lld",&A,&N);
    cmmdc(A,N,x,y);
    if (x<=0) x=N+x%N;
    printf("%lld\n",x);
    return 0;
}
