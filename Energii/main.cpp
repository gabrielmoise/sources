#include <iostream>
#include <cstdio>

using namespace std;

long long minim,maxim,g,w,i,j,x,y,v[1002][100002];
int main()
{
    freopen("energii.in","r",stdin);
    freopen("energii.out","w",stdout);
    scanf("%lld",&g);
    scanf("%lld",&w);
    maxim=0;
    for (i=1;i<=g;i++)
    {
        scanf("%lld%lld",&x,&y);
        for (j=1;j<=maxim;j++) v[i][j]=v[i-1][j];
        v[i][0]=1;
        for (j=1;j<=maxim;j++) if (v[i][j]>0) if (j+x<100002) if (v[i][j+x]==0) v[i][j+x]=v[i][j]+y;
                                                              else if (v[i][j+x]>0) if (v[i][j+x]>(v[i][j]+x)) v[i][j+x]=v[i][j]+y;
        if (v[i][x]<y) v[i][x]=y;
        maxim=maxim+x;
    }
    minim=10000000000;
    for (i=w;i<=maxim;i++) if ((minim>v[g][i]) && (v[g][i]>0)) minim=v[g][i];
    printf("%lld",minim);
    return 0;
}
