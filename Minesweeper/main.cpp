#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("minesweeper2.in","r",stdin);
    freopen("minesweeper2.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++) scanf("%d",&v[i]);
    x[0]=1; x[n+1]=1;
    v[1]++; v[n]++;
    for (i=1;i<=n;i++) if (v[i]==3) {v[i-1]=v[i-1]-2; v[i+1]=v[i+1]-2}

}
