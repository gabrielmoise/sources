#include <iostream>
#include <cstdio>

using namespace std;

long a[1000005],n,i,x,nr;

int main()
{
    freopen("elmaj.in","r",stdin);
    freopen("elmaj.out","w",stdout);
    scanf("%ld",&n);
    scanf("%ld",&a[1]);
    nr=1; x=a[1];
    for (i=2;i<=n;i++) {scanf("%ld",&a[i]);
                        if (x!=a[i]) {if (nr>0) nr--; if (nr==0) x=a[i];}
                                               else nr++;}
    nr=0;
    for (i=1;i<=n;i++) if (a[i]==x) nr++;
    printf("%ld %ld\n",x,nr);
    return 0;
}
