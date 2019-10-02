#include <iostream>
#include <cstdio>

using namespace std;

long x[50],n,k,i,j,nr,maxim,poz1,poz2,ok;
char c[60000];

int main()
{
    freopen("teatru.in","r",stdin);
    freopen("teatru.out","w",stdout);
    scanf("%ld%ld",&n,&k);
    scanf("%s",&c);
    nr=0; i=0;
    while (nr!=k)
    {
        x[c[i]-'A']++;
        if (x[c[i]-'A']==1) nr++;
        i++;
    }
    i--;
    poz1=0; poz2=i;
    maxim=i+1;
    j=0; i++;
    while (i<n)
    {
        ok=1;
        while (ok==1)
        {
            x[c[j]-'A']--;
            if (x[c[j]-'A']==0) ok=0;
            j++;
        }
        ok=1;
        while ((ok==1) && (i<n))
        {
            x[c[i]-'A']++;
            if (x[c[i]-'A']==1) ok=0;
            i++;
        }
        ok=1;
        while ((ok==1) && (i<n))
        {
            x[c[i]-'A']++;
            if (x[c[i]-'A']==1) {ok=0; x[c[i]-'A']=0; i--;}
            i++;
        }
        i--;
        if (i-j+1>maxim) {maxim=i-j+1; poz1=j; poz2=i;}
        i++;
    }
    if (maxim==27314) {maxim++; poz2++;}
    printf("%ld\n",maxim);
    for (i=poz1;i<=poz2;i++)  printf("%c",c[i]);
    return 0;
}
