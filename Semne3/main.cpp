#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long v[500005],i,j,n,poz,nr,aux,a,b;
char sir[500005];
int main()
{
    freopen("semne3.in","r",stdin);
    freopen("semne3.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) v[i]=i;
    scanf("%s",&sir);
    for (i=0;i<=n-2;i++)
    {
        if (sir[i]=='<')
            {    nr++; a=poz; b=poz+nr-1;
                 if (nr>1) for (j=a;j<=(a+b)/2;j++) {aux=v[j];v[j]=v[b-j+a];v[b-j+a]=aux;}
                           poz=0;nr=0;}
        else if (sir[i]=='>') {if (poz==0) poz=i+1; nr++;}
    }
    if (sir[n-2]=='>') {    nr++; a=poz; b=poz+nr-1;
                 if (nr>1) for (j=a;j<=(a+b)/2;j++) {aux=v[j];v[j]=v[b-j+a];v[b-j+a]=aux;}
                           poz=0;nr=0;}
    for (i=1;i<=n;i++) printf("%ld ",v[i]);
    return 0;
}
