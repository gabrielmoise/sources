#include <iostream>
#include <cstdio>

using namespace std;

long a[205][205],x,y,z,v,n,i,j,poz1,poz2,dir,p;

int main()
{
    freopen("cub2.in","r",stdin);
    freopen("cub2.out","w",stdout);
    scanf("%ld",&p);
    scanf("%ld%ld",&n,&v);
    if (p==1)
    {
        z=(v-1)/(n*n)+1;
        v=(v-1)%(n*n);
        for (i=0;i<=n+1;i++) {a[i][0]=-1; a[i][n+1]=-1;}
        for (j=0;j<=n+1;j++) {a[0][j]=-1; a[n+1][j]=-1;}
        dir=2; poz1=1; poz2=1; //1=NORD 2=EST 3=SUD 4=VEST
        for (i=1;i<=n*n;i++)
        {
            a[poz1][poz2]=i;
            if (dir==2) {if (a[poz1][poz2+1]!=0) {dir=3; poz1++;}
                            else poz2++;}
            else if (dir==3) {if (a[poz1+1][poz2]!=0) {dir=4; poz2--;}
                                 else poz1++;}
            else if (dir==4) {if (a[poz1][poz2-1]!=0) {dir=1; poz1--;}
                                 else poz2--;}
            else if (dir==1) {if (a[poz1-1][poz2]!=0) {dir=2; poz2++;}
                                 else poz1--;}
        }
        if (z%2==1) {
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++) if ((a[i][j]-1)==v) {x=i; y=j; break;} }
        else if (z%2==0) {
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++) if ((n*n-a[i][j])==v) {x=i; y=j; break;} }
        printf("%ld %ld %ld\n",x,y,z);
    }
    return 0;
}
