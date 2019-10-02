#include <iostream>
#include <cstdio>

using namespace std;

long i,l,n,k,v[20005];
int main()
{
    freopen("magicsequence.in","r",stdin);
    freopen("magicsequence.out","w",stdout);
    scanf("%ld",&n);
    for (l=1;l<=n;l++)
    {
        scanf("%ld",&k);
        for (i=1;i<=k;i++) scanf("%ld",&v[i]);
        if (v[1]>v[k]) printf("%s\n","NO");
            else printf("%s\n","YES");
    }
    return 0;
}

