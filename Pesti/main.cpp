#include <iostream>
#include <cstdio>

using namespace std;

long long p,i,n,x,q,pozc,poz,u,a,b,j;
long v[1000];


int main()
{
    freopen("pesti.in","r",stdin);
    freopen("pesti.out","w",stdout);
    scanf("%lld%lld",&n,&x);
    p=1;
    for (i=1;i<=n;i++) {p=p*2; if (p>n) break;}
    printf("%lld ",i-1);
    q=i-1;
    poz=x; pozc=x; u=0; a=1; b=n;
    for (i=1;i<=q;i++)
    {
        if ((pozc-a-1)%2==0) {pozc=(1+b+pozc)/2; a=(a+b)/2+1;}
        else {pozc=(pozc+a)/2; b=(a+b)/2;}
        poz=pozc;
        v[i]=poz;
    }
    v[0]=x;
    for (j=q;j>=0;j--) if (v[j]!=v[j-1]) {u=j; break;}
    if (u==0) u=1;
    printf("%lld %lld",poz,u);
    return 0;
}
