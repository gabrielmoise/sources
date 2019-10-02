#include <iostream>
#include <cstdio>

using namespace std;

long s[2100][2100];
long um1[150],um2[150];
long a,b,u,n,m,i,j,nr,x1,y1,x2,y2,ok,sum;

int main()
{
    freopen("plaja.in","r",stdin);
    freopen("plaja.out","w",stdout);
    scanf("%ld%ld%ld",&a,&b,&u);
    for (i=1;i<=u;i++) {scanf("%ld%ld",&um1[i],&um2[i]);}
    scanf("%ld",&n);
    nr=0;
    for (i=1;i<=n;i++)
    {
        scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
        for (j=1;j<=u;j++)
        {
            ok=1;
            if ((x1<=um1[j]) && (um1[j]<=x2) && (y1<=um2[j]) && (um2[j]<=y2)) {ok=0; break;}
        }
        if (ok==1) {nr++;
        s[x1][y1]++;
        s[x2+1][y1]--;
        s[x1][y2+1]--;
        s[x2+1][y2+1]++;}
    }
    printf("%ld ",nr);
    scanf("%ld",&m);
    for (i=1;i<=a;i++)
		for (j=1;j<=b;j++) s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    for (i=1;i<=u;i++) s[um1[i]][um2[i]]=1;
    for (i=1;i<=a;i++)
		for (j=1;j<=b;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
    nr=m;
    for (i=1;i<=m;i++)
    {
        scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
        sum=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
        ok=1;
        for (j=1;j<=u;j++)
            if ((x1<=um1[j]) && (um1[j]<=x2) && (y1<=um2[j]) && (um2[j]<=y2)) {ok=0; break;}
        if ((sum!=0) || (ok==0)) nr--;
    }
    printf("%ld\n",nr);
    return 0;
}
