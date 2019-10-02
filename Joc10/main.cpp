#include <iostream>
#include <cstdio>

using namespace std;

int a[405][905];
int poz[905];
int n,m,i,j,ind,cam,et,nr,ok,aux;

int main()
{
    freopen("joc10.in","r",stdin);
    freopen("joc10.out","w",stdout);
    scanf("%ld%ld",&n,&m);
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
    ok=0;
    for (i=1;i<=n;i++) poz[i]=1;
    for (i=1;i<=n;i++) a[i][0]=-1;
    et=0; ind=0; cam=0; nr=0;
    while (ok==0)
    {
        for (i=1;i<=n;i++)
            if (a[i][poz[i]]>=0)
        {
            if (a[i][poz[i]]==9999) {ok=1; ind=i; cam=poz[i];}
            else if (a[i][poz[i]]==0) {nr++; poz[i]=0;}
            else if (a[i][poz[i]]%10>0) a[i][poz[i]]--;
               else {aux=poz[i];
                    a[i][poz[i]]=a[i][poz[i]]/10;
                     poz[i]=a[i][poz[i]];
                     a[i][aux]=-1;}
        }
        et++;
    }
    printf("%d %d %d %d\n",ind,cam,et,nr);
    return 0;
}
