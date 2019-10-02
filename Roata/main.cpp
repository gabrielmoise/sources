#include <iostream>
#include <cstdio>

using namespace std;

long n,p,i,sum,v[100005],x[100005],z[100005],t[100005],minim,maxim,pozmaxim,k,j,poz;
void quick(long p_in,long p_sf)
{
long long a,b,mij,temp;
    a=p_in;
    b=p_sf;
    mij=v[(a+b)/2];
    do
    {
        while (v[a]<mij) a=a+1;
        while (v[b]>mij) b=b-1;
        if (a<=b)
        {
            if (v[a]!=v[b]) {temp=v[b]; v[b]=v[a]; v[a]=temp;
            temp=x[b]; x[b]=x[a]; x[a]=temp;
            temp=t[b]; t[b]=t[a]; t[a]=temp;}
            a++;b--;
        }
    }
    while (b>=a);
    if (a<p_sf) quick(a,p_sf);
    if (p_in<b) quick(p_in,b);
}

int main()
{
   freopen("roata.in","r",stdin);
   freopen("roata.out","w",stdout);
   scanf("%ld",&n); scanf("%ld",&p);
   for (i=1;i<=p;i++) {scanf("%ld",&v[i]); sum=sum+v[i];}
   printf("%ld\n",sum);
   poz=n+1;
   for (i=1;i<=p;i++) x[i]=i;
   k=1;
   for (i=1;i<=p-n;i++)
   {
       minim=100005;
       for (j=1;j<=n;j++) if (minim>v[j]) minim=v[j];
       for (j=1;j<=n;j++) {
                             v[j]=v[j]-minim;
                             if (v[j]==0) {v[j]=v[poz];
                             z[k]=x[j];
                             k++;
                             x[j]=x[poz];
                             poz++;}
                          }
   }
    for (i=1;i<=k-1;i++) printf("%ld ",z[i]);
    quick(1,n);
    for (i=1;i<=n;i++) printf("%ld ",x[i]);
    for (i=1;i<=p-n;i++) t[i]=i;
    printf("\n");
    printf("%ld\n",t[p-n]);
    return 0;
}
