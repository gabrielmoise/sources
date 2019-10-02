#include <iostream>
#include <cstdio>

using namespace std;

long a[500][500];
long i,j,l,n,m,lung,lat,aux,maxim,nr,x,y;

int main()
{
    freopen("origami.in","r",stdin);
    freopen("origami.out","w",stdout);
    scanf("%ld",&n); scanf("%ld",&nr);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) a[i][j]=1;
    lung=n; lat=n;
    for (i=1;i<=nr;i++)
    {
        scanf("%ld%ld",&x,&y);
        if (x==1)
        {
            if (2*y<=lat)
            {
                for (j=1;j<=lung;j++)
                    for (l=y+1;l<=2*y;l++) a[j][l]=a[j][l]+a[j][2*y-l+1];
                for (j=1;j<=lung;j++)
                    for (l=1;l<=lat-y;l++) {a[j][l]=a[j][l+y]; a[j][l+y]=0;}
                lat=lat-y;
            }
            else if (2*y>lat)
            {
                for (j=1;j<=lung;j++)
                    for (l=1;l<=2*y-lat;l++) {aux=a[j][l]; a[j][l]=a[j][2*y-l+1]; a[j][2*y-l+1]=aux;}
                for (j=1;j<=lung;j++)
                    for (l=1;l<=lat;l++) {a[j][l]=a[j][l+2*y-lat]; a[j][l+2*y-lat]=0;}
                y=lat-y;
                for (j=1;j<=lung;j++)
                    for (l=y+1;l<=2*y;l++) a[j][l]=a[j][l]+a[j][2*y-l+1];
                for (j=1;j<=lung;j++)
                    for (l=1;l<=lat-y;l++) {a[j][l]=a[j][l+y]; a[j][l+y]=0;}
                lat=lat-y;
            }
        }
        else if (x==2)
        {
            if (2*y<=lung)
             {
                 for (j=1;j<=lat;j++)
                     for (l=y+1;l<=2*y;l++) a[l][j]=a[l][j]+a[2*y-l+1][j];
                 for (j=1;j<=lat;j++)
                     for (l=1;l<=lung-y;l++) {a[l][j]=a[l+y][j]; a[l+y][j]=0;}
                 lung=lung-y;
             }
             else if (2*y>lung)
             {
                 for (j=1;j<=lat;j++)
                     for (l=1;l<=2*y-lung;l++) {aux=a[l][j]; a[l][j]=a[2*y-l+1][j]; a[2*y-l+1][j]=aux;}
                 for (j=1;j<=lat;j++)
                     for (l=1;l<=lung;l++) {a[l][j]=a[l+2*y-lung][j]; a[l+2*y-lung][j]=0;}
                 y=lung-y;
                 for (j=1;j<=lat;j++)
                     for (l=y+1;l<=2*y;l++) a[l][j]=a[l][j]+a[2*y-l+1][j];
                 for (j=1;j<=lat;j++)
                     for (l=1;l<=lung-y;l++) {a[l][j]=a[l+y][j];}
                 lung=lung-y;
             }
        }
    }
    maxim=0;
    for (i=1;i<=lung;i++)
        for (j=1;j<=lat;j++) if (maxim<a[i][j]) maxim=a[i][j];
    printf("%ld %ld %ld\n",lung,lat,maxim);
    /*for (i=1;i<=lung;i++) {
        for (j=1;j<=lat;j++) printf("%ld ",a[i][j]); printf("\n");}*/
    return 0;
}
