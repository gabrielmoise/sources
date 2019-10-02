#include <iostream>
#include <cstdio>

using namespace std;

long i,n,nr,j;
char v[2000002];

int main()
{
    freopen("ciur.in","r",stdin);
    freopen("ciur.out","w",stdout);
    scanf("%ld",&n);
    v[0]=1; v[1]=1;
    for (i=2;i<=n/2;i++) v[2*i]=1;
    i=3;
    while (i<=n)
    {
        if (v[i]==0)
        {
            j=i*2;
            while(j<=n) {v[j]=1; j=j+i;}
        }
        i=i+2;
    }
    nr=0;
    for (i=2;i<=n;i++) if (v[i]==0) nr++;
    printf("%ld\n",nr);
    return 0;
}
