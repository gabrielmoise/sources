#include <iostream>
#include <cstdio>

using namespace std;

long x1[1005], x2[1005],y1[1005],y2[1005],mat[1505][1505],lin[1505],col[1505];
long p,n,m,k,i,lung,lat,maxim,nr,a,b,c,d,j,l;

int main()
{
    freopen("harta5.in","r",stdin);
    freopen("harta5.out","w",stdout);
    scanf("%ld",&p);
    scanf("%ld%ld%ld",&n,&m,&k);
    if (p==1)
    {
        maxim=0;
        for (i=1;i<=k;i++)
        {
            scanf("%ld%ld%ld%ld",&x1[i],&y1[i],&x2[i],&y2[i]);
            lung=x2[i]-x1[i]+1; lat=y2[i]-y1[i]+1;
            if ((lung==lat) && (lung>maxim)) maxim=lung;
        }
        nr=0;
        for (i=1;i<=k;i++)
        {
            lung=x2[i]-x1[i]+1; lat=y2[i]-y1[i]+1;
            if ((lung<=maxim-2) && (lat<=maxim-2)) nr++;
        }
        printf("%ld %ld\n",maxim*maxim,nr);
    }
    if (p==2)
    {
        for (i=1;i<=k;i++)
            {
                scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
                for (j=a;j<=c;j++) {mat[j][b]=1; mat[j][d]=1;}
                for (j=b;j<=d;j++) {mat[a][j]=1; mat[c][j]=1;}
                for (j=a;j<=c;j++) lin[j]++;
                for (j=b;j<=d;j++) col[j]++;
            }
        for (i=1;i<=n-1;i++) if ((lin[i]==0) && (lin[i+1]==0)) lin[i]=-1;
        for (i=1;i<=m-1;i++) if ((col[i]==0) && (col[i+1]==0)) col[i]=-1;
        for (i=1;i<=n;i++){
            for (j=1;j<=m;j++) if ((lin[i]>=0) && (col[j]>=0)) printf("%ld ",mat[i][j]);
            if (lin[i]>=0) printf("\n");}
    }
    return 0;
}
