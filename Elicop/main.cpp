#include <iostream>
#include <cstdio>

using namespace std;

long m,n,i,j,l,k,l1,l2,c1,c2,nr,nr0,nr1,v[50],a[105][105],t,p,lg,aux,r1,s;
int main()
{
    freopen("elicop.in","r",stdin);
    freopen("elicop.out","w",stdout);
    scanf("%ld%ld",&m,&n);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++) scanf("%ld",&a[i][j]);
    nr=0;
    scanf("%ld",&k);
    for (l=1;l<=k;l++)
    {
        scanf("%ld%ld%ld%ld%ld",&l1,&c1,&l2,&c2,&p);
        if ((l1>l2) || ((l1==l2) && (c1>c2))) {aux=l1; l1=l2; l2=aux; aux=c1; c1=c2; c2=aux;}
        nr0=0; nr1=0;
        //Cazul I
        t=0;
        if ((c1>c2) && (p==1)) for (i=l1;i<=l2;i++)
                                   { for (j=c2;j<=c1-t;j++) if (a[i][j]==0) nr0++;
                                                               else nr1++;
                                     t++;}
        //Cazul II
        t=0;
        if ((c1<c2) && (p==1)) for (i=l1;i<=l2;i++)
                                   { for (j=c1+t;j<=c2;j++) if (a[i][j]==0) nr0++;
                                                                else nr1++;
                                     t++;}
        //Cazul III
        t=0;
        if ((c1<c2) && (p==-1)) for (i=l1;i<=l2;i++)
                                   { for (j=c1;j<=c1+t;j++) if (a[i][j]==0) nr0++;
                                                                else nr1++;
                                     t++;}
        //Cazul IV
        t=0;
        if ((c1>c2) && (p==-1)) for (i=l1;i<=l2;i++)
                                   { for (j=c1-t;j<=c1;j++) if (a[i][j]==0) nr0++;
                                                                else nr1++;
                                     t++;}
        lg=l2-l1+1;
        s=(lg*(lg+1))/2;
        if (nr1==s) r1++;
        if (nr0>(s/2))  {nr++; v[nr]=l;}
    }
    printf("%ld\n",r1);
    printf("%ld ",nr);
    for (i=1;i<=nr;i++) printf("%ld ",v[i]);
    return 0;
}
