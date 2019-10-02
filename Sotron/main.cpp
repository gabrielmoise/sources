#include <iostream>
#include <cstdio>

using namespace std;

long i,j,n,sum,smax,poz1,poz2,k,q,r;
long a[550][550],s[1000];

int main()
{
    freopen("sotron.in","r",stdin);
    freopen("sotron.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) scanf("%ld",&a[i][j]);
    smax=0;
    if (n%2==0)
    {
        i=1;
        for (i=1;i<=n;i++) if (i%2==1)
        {
            poz1=i; poz2=1; k=1;
            for (q=1;q<=500;q++) s[q]=0;
            while ((poz1>=1) && (poz2<=n))
            {
                s[k]=s[k-1]+a[poz1][poz2];
                if ((poz1+poz2)%2==1) {poz2=poz2+1;}
                else {poz1=poz1-1;}
                k++;
            }
            k--;
            for (q=1;q<=k;q++)
                for (r=q;r<=k;r++)
            {
                sum=s[r]-s[q-1];
                if (sum>smax) smax=sum;
            }
        }
        for (j=1;j<=n;j++) if (j%2==1)
        {
            poz1=n; poz2=j; k=1;
            for (q=1;q<=500;q++) s[q]=0;
            while ((poz1>=1) && (poz2<=n))
            {
                s[k]=s[k-1]+a[poz1][poz2];
                if ((poz1+poz2)%2==1) {poz2=poz2+1;}
                else {poz1=poz1-1;}
                k++;
            }
            k--;
            for (q=1;q<=k;q++)
                for (r=q;r<=k;r++)
            {
                sum=s[r]-s[q-1];
                if (sum>smax) smax=sum;
            }
        }
    }
    if (n%2==1)
    {
        i=1;
        for (i=1;i<=n;i++) if (i%2==1)
        {
            poz1=i; poz2=1; k=1;
            for (q=1;q<=500;q++) s[q]=0;
            while ((poz1>=1) && (poz2<=n))
            {
                s[k]=s[k-1]+a[poz1][poz2];
                if ((poz1+poz2)%2==1) {poz2=poz2+1;}
                else {poz1=poz1-1;}
                k++;
            }
            k--;
            for (q=1;q<=k;q++)
                for (r=q;r<=k;r++)
            {
                sum=s[r]-s[q-1];
                if (sum>smax) smax=sum;
            }
        }
        for (q=1;q<=500;q++) s[q]=0;
        for (j=2;j<=n;j++) if (j%2==0)
        {
            poz1=n; poz2=j; k=1;
            while ((poz1>=1) && (poz2<=n))
            {
                s[k]=s[k-1]+a[poz1][poz2];
                if ((poz1+poz2)%2==1) {poz2=poz2+1;}
                else {poz1=poz1-1;}
                k++;
            }
            k--;
            for (q=1;q<=k;q++)
                for (r=q;r<=k;r++)
            {
                sum=s[r]-s[q-1];
                if (sum>smax) smax=sum;
            }
        }
    }
    printf("%ld\n",smax);
    return 0;
}
