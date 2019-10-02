#include <iostream>
#include <cstdio>

using namespace std;

long n1,n2,nr1,nr2,a[2000],b[2000],v[2000],x[2000],i,j,t,c[2000];
int main()
{
    freopen("numar4.in","r",stdin);
    freopen("numar4.out","w",stdout);
    scanf("%ld%ld",&n1,&n2);
    for (i=1;i<=n1;i++) scanf("%ld",&v[i]);
    scanf("\n");
    for (i=1;i<=n1;i++) if (v[i]!=0) break;
    n1=n1-i+1; nr1=0;
    for (j=i;j<=n1+i-1;j++) {nr1++; a[nr1]=v[j];}
    for (i=1;i<=n2;i++) scanf("%ld",&x[i]);
    nr2=n2;
    for (i=nr1+1;i<=nr1+nr2;i++) a[i]=x[i-nr1];
    nr1=nr1+nr2;
    for (i=nr1;i>=1;i--) if (a[i]!=0) break;
    nr2=nr2-(nr1-i);
    nr1=i;
    nr2=nr2+1;
    b[1]=1;
    for (i=2;i<=nr2;i++) b[i]=0;
    while ((a[nr1]%2==0) || (a[nr1]==5))
    {
        if (a[nr1]==5)
        {
            if ((b[nr2]%5)!=0) break;
            t=0;
            for (i=1;i<=nr1;i++)
            {
                c[i]=(t*10+a[i])/5;
                t=(t*10+a[i])%5;
            }
            if (c[1]==0) {for (i=2;i<=nr1;i++) a[i-1]=c[i]; a[nr1]=0; nr1--;}
            else if (c[1]!=0) for (i=1;i<=nr1;i++) a[i]=c[i];
            t=0;
            for (i=1;i<=nr2;i++)
            {
                c[i]=(t*10+b[i])/5;
                t=(t*10+b[i])%5;
            }
            if (c[1]==0) {for (i=2;i<=nr2;i++) b[i-1]=c[i]; b[nr2]=0; nr2--;}
            else if (c[1]!=0) for (i=1;i<=nr2;i++) b[i]=c[i];
        }
        else if (a[nr1]%2==0)
        {
            if ((b[nr2]%2)!=0) break;
            t=0;
            for (i=1;i<=nr1;i++)
            {
                c[i]=(t*10+a[i])/2;
                t=(t*10+a[i])%2;
            }
            if (c[1]==0) {for (i=2;i<=nr1;i++) a[i-1]=c[i]; a[nr1]=0; nr1--;}
            else if (c[1]!=0) for (i=1;i<=nr1;i++) a[i]=c[i];
            t=0;
            for (i=1;i<=nr2;i++)
            {
                c[i]=(t*10+b[i])/2;
                t=(t*10+b[i])%2;
            }
            if (c[1]==0) {for (i=2;i<=nr2;i++) b[i-1]=c[i]; b[nr2]=0; nr2--;}
            else if (c[1]!=0) for (i=1;i<=nr2;i++) b[i]=c[i];
        }
    }
    for (j=1;j<=nr1;j++) if (a[j]!=0) break;
    printf("%ld",nr1-j+1);
    printf("\n");
    for (i=j;i<=nr1;i++) printf("%ld",a[i]);
    printf("\n");
    for (j=1;j<=nr1;j++) if (b[j]!=0) break;
    printf("%ld",nr2-j+1);
    printf("\n");
    for (i=j;i<=nr2;i++) printf("%ld",b[i]);
    printf("\n");
    return 0;

}
