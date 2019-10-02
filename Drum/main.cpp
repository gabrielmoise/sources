#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("drum6.in","r",stdin);
    freopen("drum6.out","w",stdout);
    scanf("%ld%ld",&n,&m);
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) {scanf("%c",x)
                        a[i][j]=(int)x;
                        scanf("\n");}
    for (i=0;i<=n+1;i++) {a[i][0]=1000; a[i][m+1]=1000;}
    for (j=0; j<=m+1;j++) {a[0][j]=1000; a[n+1][j]=1000;}
    poz1=1; poz2=1; nr=0; k=0; t=1;
    for (i=1;i<=n+m-1;i++) v[i]=1000;
    v[1]=a[1][1];
    while (!((poz1==n) && (poz2==m) && (nr==0)))
    {

    }
}
