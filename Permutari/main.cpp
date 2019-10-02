#include <iostream>
#include <cstdio>

using namespace std;

long n,i,v[100],a[100];

void perm(long x)
{long i,j;

    if (x==n) {for (i=1;i<=n;i++) printf("%ld ",v[i]); printf("\n");}
    else for (i=1;i<=n;i++) if (a[i]==0)
        {
            a[i]=1;
            v[x+1]=i;
            perm(x+1);
            a[i]=0;
        }
}

int main()
{
    freopen("permutari.in","r",stdin);
    freopen("permutari.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) {v[i]=0; a[i]=0;}
    perm(0);
    return 0;
}
