#include <iostream>
#include <cstdio>

using namespace std;

int v[300005],z[300005];
long nr,i,n,ok,s,p,j;

void backt(long x,long y)
{
    ok=1;
    for (i=x;i<=y;i++) {s=z[i-1]+z[i]+z[i+1]; if ((s!=v[i]) && (v[i]!=-1)) {ok=0; break;}}
    if (ok==1) nr++;
    nr=nr%666013;
    i=n;
    while (z[i]==1) {i--;z[i+1]=0;}
    z[i]=1;
}

int main()
{
    freopen("minesweeper2.in","r",stdin);
    freopen("minesweeper2.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) scanf("%d",&v[i]);
    if (n==1) if (v[1]==-1) printf("%d",2);
                  else printf("%d",1);
    if (n>1)
    {
        nr=0;
        for (i=1;i<=n;i++) z[i]=0;
        p=1;
        for (i=1;i<=n;i++) p=p*2;
        for (j=1;j<=p;j++) backt(1,n);
        printf("%ld",nr%666013);
    }
    return 0;
}
