#include <iostream>
#include <cstdio>

using namespace std;

long long n,i,j,v[1005];
long long s,smax,sc;
int main()
{
    freopen("expresie.in","r",stdin);
    freopen("expresie.out","w",stdout);
    scanf("%lld",&n);
    smax=0;
    for (i=1;i<=n;i++) {scanf("%lld",&v[i]); s=s+v[i];}
    for (i=1;i<=n-1;i++)
        for (j=i+1;j<=n-1;j++)
        {
            if (i==j-1) sc=s-v[i]-v[j]-v[j+1]+(v[i]*v[j]*v[j+1]);
               else sc=s-v[i]-v[i+1]-v[j]-v[j+1]+(v[i]*v[i+1])+(v[j]*v[j+1]);
            if (sc>smax) smax=sc;
        }
    printf("%lld",smax);
    return 0;

}
