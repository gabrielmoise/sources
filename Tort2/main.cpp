#include <iostream>
#include <cstdio>

using namespace std;

long a[505][505],b[505][505],m,n,k,k1,i,j,s,minim,nr;
int main()
{
    freopen("tort2.in","r",stdin);
    freopen("tort2.out","w",stdout);
    scanf("%ld%ld%ld",&m,&n,&k);
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++) scanf("%ld",&a[i][j]);
    b[i][j]=a[i][j];
    for (i=2;i<=m;i++) b[i][1]=b[i-1][1]+a[i][1];
    for (j=2;j<=n;j++) b[1][j]=b[1][j-1]+a[1][j];
    for (i=2;i<=m;i++)
      for (j=2;j<=n;j++)
        b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
    minim=2000000000;
    for (k1=0;k1<=k;k1++)
      for (i=m-k1;i<=m;i++)
        for (j=n-k+k1;j<=n;j++)
          {
              if ((i-m+k1>=0) && (j-n+k-k1>=0)) s=b[i][j]-b[i-m+k1][j]-b[i][j-n+k-k1]+b[i-m+k1][j-n+k-k1];
              if (s==minim) nr++;
              if (s<minim) {minim=s; nr=1;}
          }
    minim=b[m][n]-minim;
    printf("%ld\n",minim);
    printf("%ld\n",nr);
    return 0;
}
