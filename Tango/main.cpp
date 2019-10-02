#include <iostream>
#include <cstdio>

const long nr=999983;

using namespace std;

long long n,k,x,v[9],a[100010],i,j,m;
long long rez;

int main()
{
    freopen("tango.in","r",stdin);
    freopen("tango.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for (i=1;i<=n;i++) scanf("%lld",&a[i]);
    v[0]=1;
    for (i=1;i<=8;i++)
    {
      v[i]=0;
      for (j=1;j<=n;j++)
      {
          x=i-a[j];
          if (x>=0) v[i]=(v[i]+v[x])%nr;
      }
    }
    k=k/8; rez=1; m=v[8];
    while (k>0)
    {
        if (k%2==1) rez=(rez*m)%nr;
        m=(m*m)%nr;
        k=k/2;
    }
    printf("%lld",rez);
    return 0;
}
