#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long z[10000],n,i,nr,y,x,k,r;
double v[10000];

int main()
{
    freopen("poligon6.in","r",stdin);
    freopen("poligon6.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%ld",&r);
        for (x=1;x<=r-1;x++)
        {
            y=r*r-x*x;
            if ((sqrt(y)*sqrt(y))==y) {k++; v[k]=(sqrt(y))/x;}
        }
    }
    printf("%ld\n",k);
    sort(v+1,v+k+1);
    nr=0;
    for (i=1;i<=k;i++) if (v[i]!=v[i-1]) {nr++; z[nr]=1;}
                          else z[nr]++;
    printf("%ld\n",nr);
    for (i=1;i<=nr;i++) printf("%ld ",z[i]);
    return 0;
}
