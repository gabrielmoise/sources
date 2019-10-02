#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long n,i,nr;

int main()
{
    freopen("problema.in","r",stdin);
    freopen("problema.out","w",stdout);
    scanf("%lld",&n);
    nr=1;
    for (i=1;i<=n;i++) if (n%i==0) {printf("%lld %lld\n",nr,n/i); nr++; if (nr==11) break;}
    return 0;
}
