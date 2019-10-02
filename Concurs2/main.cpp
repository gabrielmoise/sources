#include <iostream>
#include <cstdio>

using namespace std;

long n,i,v[550],x[550],a,k,z[60][1010],j,pozmaxim1,pozmaxim2,nr,maxim;
void quick(long p_in,long p_sf)
{
  long a,b,mij,mij2,temp;
    a=p_in; b=p_sf;
    mij=v[(a+b)/2]; mij2=x[(a+b)/2];
    do
     {
      while ((v[a]<mij) || ((v[a]==mij) && (x[a]<mij2))) a=a+1;
      while ((v[b]>mij) || ((v[b]==mij) && (x[b]>mij2))) b=b-1;
      if (a<=b)
        {
            temp=v[b];
            v[b]=v[a];
            v[a]=temp;
            temp=x[b];
            x[b]=x[a];
            x[a]=temp;
            a++; b--;
        }
     }
    while (b>=a);
    if (a<p_sf) quick(a,p_sf);
    if (p_in<b) quick(p_in,b);
}
int main()
{
    freopen("concurs2.in","r",stdin);
    freopen("concurs2.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) scanf("%ld%ld",&v[i],&x[i]);
    quick(1,n);
    k=0; a=0;
    for (i=1;i<=n;i++)
    {
        if (a!=v[i]) {k++;z[k][-1]=v[i];z[k][0]++;z[k][z[k][0]]=x[i];a=v[i];}
           else {z[k][0]++;z[k][z[k][0]]=x[i];}
    }
    nr=0;
    for (i=1;i<=k;i++) z[i][-2]=z[i][0];
    printf("%ld\n",k);
    for (i=1;i<=k;i++) printf("%ld ",z[i][0]);
    printf("\n");
    pozmaxim1=0; pozmaxim2=-1;
    while (nr<n)
    {
        maxim=0; pozmaxim1=pozmaxim2; pozmaxim2=0;
        for (i=1;i<=k;i++) if ((maxim<z[i][0]) && (pozmaxim1!=i)) {maxim=z[i][0]; pozmaxim2=i;}
        printf("%ld %ld\n",z[pozmaxim2][-1],z[pozmaxim2][z[pozmaxim2][-2]-z[pozmaxim2][0]+1]);
        z[pozmaxim2][0]=z[pozmaxim2][0]-1;
        nr++;
    }
    return 0;
}
