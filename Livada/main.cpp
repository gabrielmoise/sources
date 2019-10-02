#include <iostream>
#include <cstdio>

using namespace std;

long x[105],rez1,rez2,maxim,nrmax,c,n,m,p,nr,poz,i,j;
int main()
{
    freopen("livada.in","r",stdin);
    freopen("livada.out","w",stdout);
    scanf("%ld%ld%ld",&n,&m,&p);
    rez1=0; rez2=0; maxim=0; nrmax=0; c=0;
    for (i=1;i<=n;i++)
    {
        scanf("%ld",&x[1]);
        poz=x[1]; nr=1; c=x[1]; nrmax=1;
        for (j=2;j<=m;j++)
        {
            scanf("%ld",&x[j]);
            if (x[j]!=poz) nr--;
               else nr++;
            if (nr==0) poz=x[j];
            if (x[j]==c) nrmax++;
               else {if (nrmax>maxim) {rez2=c; maxim=nrmax;} c=x[j]; nrmax=1;}
        }
        nr=0;
        for (j=2;j<=m;j++) if (x[j]==poz) nr++;
        if (nr>=(n/2)+1) rez1++;
    }
    printf("%ld\n",rez1);
    printf("%ld\n",maxim);
    return 0;
}
