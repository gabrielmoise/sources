#include <iostream>
#include <cstdio>
//PRIETENUL DIN STANGA SI DIN DREAPTA SA CU O POZITIE E AUTOMAT PRIETEN SI TREBUIE SA SE INCEAPA PARCURGEREA DE LA EL
using namespace std;

int v[20010],a[20010],b[20010],st[20010],c[20010],d[20010];
long n,i,j,nr,ind,aux;

int main()
{
    freopen("copaci4.in","r",stdin);
    freopen("copaci4.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) scanf("%d",&v[i]);
    //de la stanga la dreapta
    st[1]=v[1]; st[0]=500;
    a[1]=-1; ind=1;
    for (i=2;i<=n;i++)
    {
        while (v[i]>=st[ind]) {st[ind]=v[i]; ind--;}
        ind++;
        if (st[ind-1]==500) a[i]=-1;
           else {a[i]=1; c[i]=st[ind-1];}
    }
    for (i=1;i<=n;i++) st[i]=0;
    //de la dreapta la stanga
    st[1]=v[n]; st[0]=500;
    b[1]=-1; ind=1;
    for (i=n-1;i>=1;i--)
    {
        while (v[i]>=st[ind]) {st[ind]=v[i]; ind--;}
        ind++;
        if (st[ind-1]==500) b[n-i+1]=-1;
           else {b[n-i+1]=1; d[n-i+1]=st[ind-1];}
    }
    for (i=1;i<=n/2;i++) {aux=b[i]; b[i]=b[n-i+1]; b[n-i+1]=aux;
                          aux=d[i]; d[i]=d[n-i+1]; d[n-i+1]=aux;}
    nr=0;
    for (i=1;i<=n;i++) if ((a[i]==1) && (b[i]==1) && (c[i]!=d[i])) nr++;
    printf("%ld\n",nr);
    return 0;
}
