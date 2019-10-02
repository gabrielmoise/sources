#include <iostream>
#include <cstdio>

using namespace std;

long n,k,d,i,j,nr,maxim,x,y,v1[105],v2[105],a[1005][1005];

//GRESITA PROCEDURA DEOARECE NU E UN LEE CI MERGEM PE O SINGURA DIRECTIE
void marcare(long lin, long col,long nr)
{
   if (a[lin-1][col-1]==0) {a[lin-1][col-1]=2; nr++; marcare(lin-1,col-1,nr); }
   if (a[lin-1][col]==0) {a[lin-1][col]=2; nr++; marcare(lin-1,col,nr);}
   if (a[lin-1][col+1]==0) {a[lin-1][col+1]=2; nr++; marcare(lin-1,col+1,nr);}
   if (a[lin][col-1]==0) {a[lin][col-1]=2; nr++; marcare(lin,col-1,nr);}
   if (a[lin][col+1]==0) {a[lin][col+1]=2; nr++; marcare(lin,col+1,nr);}
   if (a[lin+1][col-1]==0) {a[lin+1][col-1]=2; nr++; marcare(lin+1,col-1,nr);}
   if (a[lin+1][col]==0) {a[lin+1][col]=2; nr++; marcare(lin+1,col,nr);}
   if (a[lin+1][col+1]==0) {a[lin+1][col+1]=2; nr++; marcare(lin+1,col+1,nr);}
}

int main()
{
    freopen("betasah.in","r",stdin);
    freopen("betasah.out","w",stdout);
    scanf("%ld%ld%ld",&n,&d,&k);
    for (i=1;i<=d;i++)
    {
        scanf("%ld%ld",&v1[i],&v2[i]);
        a[v1[i]][v2[i]]=1;
    }
    for (i=1;i<=k;i++)
    {
        scanf("%ld%ld",&x,&y);
        a[x][y]=-1;
    }
    maxim=0;
    for (i=1;i<=n;i++)
    {
        nr=0;
        for (j=1;j<=i;j++) if (a[i][j]==0) nr++;
        if (nr>maxim) maxim=nr;
    }
    printf("%ld\n",maxim);
    for (i=0;i<=n+1;i++) a[i][0]=-2;
    for (j=0;j<=n+1;j++) a[0][j]=-2;
    for (i=0;i<=n+1;i++)
        for (j=i+1;j<=i+2;j++) a[i][j]=-2;
    for (i=1;i<=d;i++) marcare(v1[i],v2[i],0);
    printf("%ld\n",nr);
    return 0;
}
