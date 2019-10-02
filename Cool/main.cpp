#include <iostream>
#include <cstdio>

using namespace std;

long v[5005],a[1005],p,n,k,i,j,maxim,minim,nrmax,lgmax,dist,ok;
int main()
{
    freopen("cool.in","r",stdin);
    freopen("cool.out","w",stdout);
    scanf("%ld",&p);
    scanf("%ld%ld",&n,&k);
    for (i=1;i<=n;i++) scanf("%ld",&v[i]);
    if (p==2)
    {
        nrmax=0; lgmax=0; ok=0;
        for (i=n;i>=1;i--)
            {
                dist=0; maxim=0; minim=20000;
                for (j=1;j<=1003;j++) a[j]=0;
                for (j=1;j<=i;j++)
                    {
                        a[v[j]]++;
                        if (maxim<v[j]) maxim=v[j];
                        if (minim>v[j]) minim=v[j];
                        if (a[v[j]]>1) dist++;
                    }
                if ((dist==0) && (maxim-minim+1==i)) {ok=1;lgmax=i;nrmax=1;}
                for (j=2;j<=n-i+1;j++)
                    {
                        a[v[j-1]]--;
                        if (a[v[j-1]]==1) dist--;
                        a[v[j+i-1]]++;
                        if (a[v[j+i-1]]>1) dist++;
                        if (maxim<v[j+i-1]) maxim=v[j+i-1];
                        if (minim>v[j+i-1]) minim=v[j+i-1];
                        if ((dist==0) && (maxim-minim+1==i)) {ok=1;lgmax=i;nrmax++;}
                    }
                if (ok==1) break;
            }
        printf("%ld\n",lgmax);
        printf("%ld\n",nrmax);
    }
    if (p==1)
    {
        dist=0; maxim=0; minim=20000;
        for (i=1;i<=k;i++)
          {
             a[v[i]]++;
             if (maxim<v[i]) maxim=v[i];
             if (minim>v[i]) minim=v[i];
             if (a[v[i]]>1) dist++;
          }
        if ((dist==0) && (maxim-minim+1==k)) printf("%ld\n",maxim);
           else printf("%ld\n",dist);
    }
    return 0;
}
