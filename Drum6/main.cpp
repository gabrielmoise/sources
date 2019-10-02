#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char x;
int a[1100][1100],vpoz1[50000],vpoz2[50000],val[50000],v[2500],t,nr,k,i,j,n,m,poz1,poz2;

int main()
{
    freopen("drum6.in","r",stdin);
    freopen("drum6.out","w",stdout);
    scanf("%ld%ld\n",&n,&m);
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {scanf("%c",&x); a[i][j]=(int)x;} scanf("\n");}
    for (i=0;i<=n+1;i++) {a[i][0]=1000; a[i][m+1]=1000;}
    for (j=0; j<=m+1;j++) {a[0][j]=1000; a[n+1][j]=1000;}
    poz1=1; poz2=1;
    nr=0; k=0; t=1;
    for (i=1;i<=n+m-1;i++) v[i]=1000;
    v[1]=a[1][1];
    while (!((poz1==n) && (poz2==m) && (nr==0)))
    {
        if (a[poz1+1][poz2]==a[poz1][poz2+1])
        {
            nr++; k++;
            vpoz1[k]=poz1; vpoz2[k]=poz2; val[k]=0;
            poz1++;
        }
        else if (a[poz1+1][poz2]<a[poz1][poz2+1]) poz1++;
        else poz2++;
        if (a[poz1][poz2]<v[poz1+poz2-1]) t=1;
        else if ((a[poz1][poz2]>v[poz1+poz2-1])  && (t!=1)) t=-1;
        if (t==-1)
        {
            i=k;
            while ((i>0) && (val[i]==1)) i--;
            if (i>0) {nr--; val[i]=1;}
            if (i>0) for (j=i+1;j<=k;j++) {val[j]=0; nr++;}
            if (i>0) {poz1=vpoz1[i]; poz2=vpoz2[i]+1;}
            if ((nr==0) && (i==0)) break;
            t=0;
        }
        else if (t==1) v[poz1+poz2-1]=a[poz1][poz2];
        if ((poz1==n) && (poz2==m) && (nr>0))
        {
            i=k;
            while ((i>0) && (val[i]==1)) i--;
            nr--; val[i]=1;
            for (j=i+1;j<=k;j++) {val[j]=0; nr++;}
            poz1=vpoz1[i]; poz2=vpoz2[i]+1; t=0;
            if (a[poz1][poz2]<v[poz1+poz2-1]) t=1;
                else if (a[poz1][poz2]>v[poz1+poz2-1]) t=-1;
        }
    }
    for (i=1;i<=n+m-1;i++) printf("%c",(char)v[i]);
    return 0;
}
