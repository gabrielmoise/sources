/*#include <iostream>
#include <cstdio>

using namespace std;

long long v[20500],x[20500],y[20500];
long long p,n,i,nr,maxim,maxval,rez,j,corect,valcur,scur;

int main()
{
    freopen("arc.in","r",stdin);
    freopen("arc.out","w",stdout);
    scanf("%lld",&p);
    scanf("%lld",&n);
    for (i=1;i<=n;i++) scanf("%lld",&v[i]);
    if (p==1)
    {
        nr=0; v[n+1]=-1;
        for (i=1;i<=n;i++) if (v[i]!=v[i+1]) nr++;
        printf("%lld\n",nr);
    }
    corect=0;
    if (p==2)
    {
        while (corect==0)
        {
            nr=1; v[n+1]=-1; x[1]=1; y[1]=v[1];
            for (i=2;i<=n;i++) if (v[i-1]==v[i]) x[nr]++;
                                   else {nr++; x[nr]=1; y[nr]=v[i];}
            maxim=0; maxval=0;
            for (i=1;i<=nr;i++) if (x[i]>maxim) {maxim=x[i]; maxval=i;}
            while (maxim>=3)
            {
                x[maxval]=-1; y[maxval]=-1;
                while (y[maxval-1]==y[maxval-y[maxval]])
                    {
                        x[maxval-1]=x[maxval-1]+x[maxval-y[maxval]];
                        x[maxval-y[maxval]]=-1; y[maxval-y[maxval]]=-1;
                        x[maxval]=x[maxval]-1; y[maxval]=y[maxval]-1;
                        maxval=maxval-1;
                        if (x[maxval]<3) break;
                        x[maxval]=x[maxval+1]-1; y[maxval]=y[maxval+1]-1;
                    }
                maxim=0;
                for (i=1;i<=nr;i++) if (x[i]>maxim) {maxim=x[i]; maxval=i;}
            }
            corect=1; valcur=10000000; scur=0;
            for (i=1;i<=nr;i++) if (y[i]>0) {if (valcur==y[i]) scur=scur+x[i];
                                                 else {valcur=y[i]; scur=x[i];}
                                             if (scur>=3) {corect=0; break;} }
            if (corect==0)
            {
                n=1;
                for (i=1;i<=nr;i++) if (x[i]>0) {for (j=n;j<=n+x[i]-1;j++) v[j]=y[i]; n=n+x[i];}
                n--;
            }
        rez=0;
        for (i=1;i<=nr;i++) if (x[i]>0) rez=rez+x[i];
        }
        printf("%lld\n",rez);
        for (i=1;i<=nr;i++) if (x[i]>0) for (j=1;j<=x[i];j++) printf("%lld\n",y[i]);
    }
    return 0;
}*/
// prof. Carmen Popescu - Colegiul National "Gheorghe Lazar" Sibiu
#include <fstream>

using namespace std;

int p;
int c[10000],x[100000],m,n;

ifstream f("arc.in");
ofstream g("arc.out");


void citire()
{
    int k,i;
    f>>p;
    f>>n;
    f>>c[1]; x[1]=1; m=1;
    for (i=2;i<=n;i++)
    {
        f>>k;
        if (k==c[m])
            x[m]++;
        else
        {
            m++;
            c[m]=k;
            x[m]=1;
        }
    }
}

int maxim()
{
    int mx,k,i;
    mx=x[1]; k=1;
    for (i=1;i<=m;i++)
        if (x[i]>mx)
        {
            mx=x[i]; k=i;
        }
    return k;
}

void elim(int k)
{
    int i,j,m1;
    if (x[k]>2)
    {
        n=n-x[k];
        i=k-1; j=k+1;
        while (c[i]==c[j] && i>=1 && j<=m && x[i]+x[j]>2)
        {
            n=n-x[i]-x[j];
            i--; j++;
        }
        if (j>m)
            m=i;
        else
        {
            if (i>=1 && j<=m && c[i]==c[j])
            {
                x[i]=x[i]+x[j];
                j++;
            }
            m1=m-j+i+1;
            i=i+1;
            while (j<=m)
            {
                x[i]=x[j]; c[i]=c[j];
                i++; j++;
            }
            m=m1;
        }
    }
}

int main()
{
    int k;
    citire();
    if (p==1)
        g<<m<<"\n";
    else
    {
        k=maxim();
        while (n>0 && x[k]>2)
        {
            elim(k);
            if (k>0)
                k=maxim();
        }
        if (n>0)
        {
            g<<n<<"\n";
            for (int i=1;i<=m;i++)
                for (int j=1;j<=x[i];j++)
                    g<<c[i]<<"\n";
        }
        else
            g<<"0\n";
    }
    g.close();
    return 0;
}

