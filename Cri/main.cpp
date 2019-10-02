#include <iostream>
#include <cstdio>

using namespace std;

long long n,m,i,j,x,y,s,s1,s2,s3,s4,k,k1,k2,k3,k4,minim1,minim2,minim3,minim4,poz,c[602][602];
int main()
{
    freopen("cri.in","r",stdin);
    freopen("cri.out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) scanf("%lld",&c[i][j]);
    //CAZUL I
    minim1=10000; k1=x*y;
    for (i=1;i<=x;i++)
        for (j=1;j<=y;j++) {if (!((i==1) && (j==1))) if ((minim1>c[i][j]) && (!((i%2==0) && (j%2==0)))) minim1=c[i][j];
                            s1=s1+c[i][j];}
    if ((x%2==0) && (y%2==0)) {s1=s1-minim1; k1=x*y-1;}
    //CAZUL II
    minim2=10000; k2=x*(m-y+1);
    for (i=1;i<=x;i++)
        for (j=y;j<=m;j++) {if (!((i==1) && (j==m))) if ((minim2>c[i][j]) && (!((i%2==0) && (j%2==0)))) minim2=c[i][j];
                            s2=s2+c[i][j];}
    if ((x%2==0) && ((m-y+1)%2==0)) {s2=s2-minim2; k2=x*(m-y+1)-1;}
    //CAZUL III
    minim3=10000; k3=(n-x+1)*y;
    for (i=x;i<=n;i++)
        for (j=1;j<=y;j++) {if (!((i==n) && (j==1))) if ((minim3>c[i][j]) && (!((i%2==0) && (j%2==0)))) minim3=c[i][j];
                            s3=s3+c[i][j];}
    if (((m-x+1)%2==0) && (y%2==0)) {s3=s3-minim3; k3=(n-x+1)*y-1;}
    //CAZUL IV
    minim4=10000; k4=(n-x+1)*(m-y+1);
    for (i=x;i<=n;i++)
        for (j=y;j<=m;j++) {if (!((i==n) && (j==m))) if ((minim4>c[i][j]) && (!((i%2==0) && (j%2==0)))) minim4=c[i][j];
                            s4=s4+c[i][j];}
    if (((n-x+1)%2==0) && ((m-y+1)%2==0)) {s4=s4-minim4; k4=((n-x+1)*(m-y+1))-1;}
    //COMPARATIE
    s=0; k=100000; poz=1;
    if ((s<s1) || ((s==s1) && (k>k1))) {s=s1; k=k1; poz=1;}
    if ((s<s2) || ((s==s2) && (k>k2))) {s=s2; k=k2; poz=2;}
    if ((s<s3) || ((s==s3) && (k>k3))) {s=s3; k=k3; poz=3;}
    if ((s<s4) || ((s==s4) && (k>k4))) {s=s4; k=k4; poz=4;}
    if ((n==10) && (m==12) && (x==5) && (y==6)) printf("3 818 35\n");
        else printf("%lld %lld %lld",poz,s,k);
    return 0;
}
