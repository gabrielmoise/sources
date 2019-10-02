#include <iostream>
#include <cstdio>

using namespace std;

long o1,m1,s1,o2,m2,s2,i,n,k,x,aux,xinv,l1,z1,l2,z2,y;
long v[86500];
long long nr;

int main()
{
    freopen("momente.in","r",stdin);
    freopen("momente.out","w",stdout);
    scanf("%ld",&k);
    //precalcul de momente de la ora 00:00:00 la 23:59:59
    o1=0; m1=0; s1=0; i=0;
    while (o1!=24)
    {
        x=0;
        x=o1;
        x=x*100+m1;
        x=x*100+s1;
        xinv=0;
        aux=x;
        while (aux!=0) {xinv=xinv*10+(aux%10); aux=aux/10;}
        if (x==xinv) v[i]=v[i-1]+1;
            else v[i]=v[i-1];
        i++; s1++;
        if (s1==60) {s1=0; m1++;}
        if (m1==60) {m1=0; o1++;}
    }
    i--; n=i;
    for (i=1;i<=k;i++)
    {
        nr=0; x=0; y=0;
        scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld",&l1,&z1,&o1,&m1,&s1,&l2,&z2,&o2,&m2,&s2);
        if (l1==1) x=0;
        else if (l1==2) x=31;
        else if (l1==3) x=31+28;
        else if (l1==4) x=31+28+31;
        else if (l1==5) x=31+28+31+30;
        else if (l1==6) x=31+28+31+30+31;
        else if (l1==7) x=31+28+31+30+31+30;
        else if (l1==8) x=31+28+31+30+31+30+31;
        else if (l1==9) x=31+28+31+30+31+30+31+31;
        else if (l1==10) x=31+28+31+30+31+30+31+31+30;
        else if (l1==11) x=31+28+31+30+31+30+31+31+30+31;
        else if (l1==12) x=31+28+31+30+31+30+31+31+30+31+30;
        x=x+z1;
        if (l2==1) y=0;
        else if (l2==2) y=31;
        else if (l2==3) y=31+28;
        else if (l2==4) y=31+28+31;
        else if (l2==5) y=31+28+31+30;
        else if (l2==6) y=31+28+31+30+31;
        else if (l2==7) y=31+28+31+30+31+30;
        else if (l2==8) y=31+28+31+30+31+30+31;
        else if (l2==9) y=31+28+31+30+31+30+31+31;
        else if (l2==10) y=31+28+31+30+31+30+31+31+30;
        else if (l2==11) y=31+28+31+30+31+30+31+31+30+31;
        else if (l2==12) y=31+28+31+30+31+30+31+31+30+31+30;
        y=y+z2;
        if (x<y) {nr=nr+699*(y-x-1);
                  nr=nr+699-v[60*60*o1+60*m1+s1-1]+v[60*60*o2+60*m2+s2];}
        if (y==x) nr=nr+v[60*60*o2+60*m2+s2]-v[60*60*o1+60*m1+s1-1];
        //printf("%ld %ld %ld ",v[60*60*o1+60*m1+s1-1],v[60*60*o1+60*m1+s1],v[60*60*o2+60*m2+s2]);
        printf("%lld\n",nr);
    }
    return 0;
}
