#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct rec{long a1,a2,b1,b2,c1,c2;};
rec t[100];

double arie1,arie2,arie3,arie;
long n,f1,f2,nr,i,v[100];

int main()
{
    freopen("triunghi2.in","r",stdin);
    freopen("triunghi2.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
        {
            scanf("%ld%ld%ld%ld%ld%ld",&t[i].a1,&t[i].a2,&t[i].b1,&t[i].b2,&t[i].c1,&t[i].c2);
            tga=t[i].a2/t[i].a1;
            tgb=t[i].b2/t[i].b1;
            tgc=t[i].c2/t[i].c1;
            if (tga>tgb) {aux=t[i].a1; t[i].a1=t[i].b1; t[i].b1=aux;
                          aux=t[i].a2; t[i].a2=t[i].b2; t[i].b2=aux;}

    scanf("%ld%ld",&f1,&f2);
    nr=0;
    for (i=1;i<=n;i++)
    {
        arie1=
        arie2=t[i].c1*f2-t[i].c2*f1+t[i].b1*f2-t[i].b2*f1+t[i].c1*t[i].b2-t[i].c2*t[i].b1;
        arie3=t[i].a1*f2-t[i].a2*f1+t[i].c1*f2-t[i].c2*f1+t[i].a1*t[i].c2-t[i].a2*t[i].c1;
        arie=t[i].a1*t[i].c2-t[i].a2*t[i].c1+t[i].b1*t[i].c2-t[i].b2*t[i].c1+t[i].a1*t[i].b2-t[i].a2*t[i].b1;
        if (arie==arie1+arie2+arie3) {nr++; v[nr]=i;}
    }
    printf("%ld ",nr);
    for (i=1;i<=nr;i++) printf("%ld ",v[i]);
    printf("\n");
    return 0;
}
