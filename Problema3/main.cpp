#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

char x;
int a[1100][1100],i,j,n,m,poz1,poz2;

int main()
{
    freopen("drum6.in","r",stdin);
    freopen("drum6.out","w",stdout);
    scanf("%ld",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {scanf("%c",&x); a[i][j]=(int)x;}
    for (i=0;i<=n+1;i++) {a[i][0]=1000; a[i][m+1]=1000;}
    for (j=0; j<=m+1;j++) {a[0][j]=1000; a[n+1][j]=1000;}
    poz1=1; poz2=1; printf("%c",(char)a[1,1]);
    while (!((poz1==n) && (poz2==m)))
    {
        if (a[poz1+1][poz2]<a[poz1][poz2+1]) poz1++;
                            else poz2++;
        printf("%c",(char)a[poz1][poz2]);
    }
    return 0;
}
