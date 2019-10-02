#include <iostream>
#include <cstdio>

using namespace std;

long n,i,j,l,nr,v1[1000],v2[1000],v3[1000];

int main()
{
    freopen("mate.in","r",stdin);
    freopen("mate.out","w",stdout);
    scanf("%ld",&n);
    nr=0;
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
            for (l=j+1;l<=n;l++) if ((j*j==i*l) && (j%i==0) && (l%j==0) && (j/i==l/j)) {nr++; v1[nr]=i; v2[nr]=j; v3[nr]=l;}
    printf("%ld\n",nr);
    for (i=1;i<=nr;i++) printf("%ld %ld %ld\n",v1[i],v2[i],v3[i]);
    return 0;
}
