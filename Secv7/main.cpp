#include <iostream>
#include <cstdio>

using namespace std;

long v[31000];
long n,i,maxim,maxim1,maxim2,maxim3,pozmax,minim,minim1,minim2,minim3,ind1,ind2,ind11,ind12,ind21;
long ind22,ind31,ind32;

int main()
{
    freopen("secv7.in","r",stdin);
    freopen("secv7.out","w",stdout);
    scanf("%ld",&n);
    maxim=-20000; pozmax=0;
    for (i=1;i<=n;i++) {scanf("%ld",&v[i]); if (v[i]>maxim) {maxim=v[i]; pozmax=i;}}
    //STANGA
    maxim1=maxim; minim1=40000;
    maxim3=-20000; ind11=0; ind12=0;
    for(i=n;i>pozmax+1;i--)
    {
        if (v[i]>maxim3) maxim3=v[i];
        maxim2=v[i-1];
        if (minim1>maxim1+maxim2+maxim3) {minim1=maxim1+maxim2+maxim3; ind11=i-2; ind12=i-1;}
    }
    //MIJLOC
    maxim1=v[1];
    maxim2=maxim; minim2=40000;
    maxim3=v[n]; ind21=0; ind22=0;
    if (minim2>maxim1+maxim2+maxim3) {minim2=maxim1+maxim2+maxim3; ind21=1; ind22=n-1;}
    //DREAPTA
    maxim1=-20000; minim3=40000;
    maxim3=maxim; ind31=0; ind32=0;
    for (i=1;i<pozmax-1;i++)
    {
        if (v[i]>maxim1) maxim1=v[i];
        maxim2=v[i+1];
        if (minim3>maxim1+maxim2+maxim3) {minim3=maxim1+maxim2+maxim3; ind31=i; ind32=i+1;}
    }
    minim=40000; ind1=0; ind2=0;
    if (minim>minim1) {minim=minim1; ind1=ind11; ind2=ind12;}
    if (minim>minim2) {minim=minim2; ind1=ind21; ind2=ind22;}
    if (minim>minim3) {minim=minim3; ind1=ind31; ind2=ind32;}
    printf("%ld\n",minim);
    printf("%ld %ld\n",ind1,ind2);
    return 0;
}
