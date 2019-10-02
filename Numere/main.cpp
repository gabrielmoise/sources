#include <iostream>
#include <cstdio>

using namespace std;

long v[25000],n,k,minim,maxim,i,j,x,ok;

void quick(long p_in,long p_sf)
{
  long a,b,mij,mij2,temp;
  a=p_in; b=p_sf;
  mij=v[(a+b)/2];
  do
   {
    while (v[a]<mij) a++;
    while (v[b]>mij) b--;
    if (a<=b)
      {
          temp=v[b];
          v[b]=v[a];
          v[a]=temp;
          a++; b--;
      }
   }
  while (b>=a);
  if (a<p_sf) quick(a,p_sf);
  if (p_in<b) quick(p_in,b);
}

int main()
{
    freopen("numere.in","r",stdin);
    freopen("numere.out","w",stdout);
    scanf("%ld",&n);
    k=1;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
    {
        scanf("%ld",&x);
        if (x!=0) {v[k]=x; k++;}
    }
    k--;
    quick(1,k);
    minim=0; maxim=0;
    for (i=1;i<=k;i++) if (i!=v[i]) {minim=i; break;}
    ok=n*n;
    for (i=k;i>=1;i--) if (ok!=v[i]) {maxim=ok; break;}
                        else ok--;
    printf("%ld %ld",minim,maxim);
    return 0;
}
