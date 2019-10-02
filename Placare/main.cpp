#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
long a[305][305],i,j,l,n,m,lin,col,nr,z,x;
char sir[1000];
int main()
{
    freopen("placare.in","r",stdin);
    freopen("placare.out","w",stdout);
    scanf("%ld%ld\n",&n,&m);
    for (i=1;i<=n;i++)
    {
        gets(sir);
        x=strlen(sir);
        if (sir[j]!='0') {nr=0; z=1; lin=0; col=0;
        for (j=0;j<=x-1;j++)
        {
            if (sir[j]==' ')
            {
                for (l=1;l<=m;l++) if (a[i][l]==0) {col=l; break;}
                lin=i;
                if (nr>0) for (l=col;l<=col+nr-1;l++) a[lin][l]=nr;
                if (nr<0) for (l=lin;l<=lin-nr-1;l++) a[l][col]=-nr;
                nr=0; z=1; lin=0; col=0;
            }
            else if (sir[j]=='-') z=-1;
            else  nr=nr*10+z*(int(sir[j])-int('0'));
        }
        for (l=1;l<=m;l++) if (a[i][l]==0) {col=l; break;}
        lin=i;
        if (nr>0) for (l=col;l<=col+nr-1;l++) a[lin][l]=nr;
        if (nr<0) for (l=lin;l<=lin-nr-1;l++) a[l][col]=-nr;
        nr=0; z=1; lin=0; col=0;}
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++) printf("%ld ",a[i][j]);
        printf("\n");
    }
    return 0;
}
