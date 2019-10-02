#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

long n,i,j,nr;
bitset <2000005> v;

int main()
{
    freopen("ciur.in","r",stdin);
    freopen("ciur.out","w",stdout);
    scanf("%ld",&n);
    i=2;
    while (i<=n) {i=i+2; v[i]=1;}
    i=3;
    while (i<=n) if (v[i]==0)
    {
        j=i*2;
        while (j<=n) {v[j]=1; j=j+i;}
        i=i+2;
    }
    else i=i+2;
    nr=0;
    for (i=2;i<=n;i++) if (v[i]==0) nr++;
    printf("%ld",nr);
    return 0;
}
