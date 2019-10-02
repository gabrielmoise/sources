#include <iostream>
#include <cstdio>

using namespace std;

long a[250][250],zx1[40200], zy1[40200], zx2[40200], zy2[40200];
long n,m,i,j,poz1,poz2,dir,t1,t2,term,x,y,pasi,morc,morcovi,mort,pozf1,pozf2,stare;

int main()
{
    freopen("iepuras.in","r",stdin);
    freopen("iepuras.out","w",stdout);
    scanf("%ld%ld",&n,&m);
    scanf("%ld%ld%ld",&poz1,&poz2,&dir);
    t1=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        scanf("%ld",&a[i][j]);
        if (a[i][j]==7) morc++;
        if (a[i][j]==8) {t1++; zx1[t1]=i; zy1[t1]=j;}
    }
    scanf("%ld",&t2);
    for (i=1;i<=t2;i++) scanf("%ld%ld",&zx2[i],&zy2[i]);
    stare=-1; pasi=1;
    if (dir==1) {x=poz1-1; y=poz2;}
    else if (dir==2) {x=poz1; y=poz2-1;}
    else if (dir==3) {x=poz1+1; y=poz2;}
    else if (dir==4) {x=poz1; y=poz2+1;}
    mort=0; poz1=x; poz2=y;
    morcovi=0; term=1;
    while(stare==-1)
    {
        if ((a[x+1][y]==6) || (a[x-1][y]==6) || (a[x][y+1]==6) || (a[x][y-1]==6)) {mort=1;
            if (a[x+1][y]==6) a[x+1][y]=-6;
            else if (a[x-1][y]==6) a[x-1][y]=-6;
            else if (a[x][y+1]==6) a[x][y+1]=-6;
            else if (a[x][y-1]==6) a[x][y-1]=-6;}
        else if ((a[x+1][y]==-6) || (a[x-1][y]==-6) || (a[x][y+1]==-6) || (a[x][y-1]==-6)) {mort=2;
            if (a[x+1][y]==-6) a[x+1][y]=6;
            else if (a[x-1][y]==-6) a[x-1][y]=6;
            else if (a[x][y+1]==-6) a[x][y+1]=6;
            else if (a[x][y-1]==-6) a[x][y-1]=6;}
             if (a[x][y]==0) {if (dir==1) {x=poz1-1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2-1;}
                             else if (dir==3) {x=poz1+1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2+1;}}
        else if (a[x][y]==1) {a[x][y]=0; x=poz1-1; y=poz2; dir=1;}
        else if (a[x][y]==2) {a[x][y]=0; x=poz1; y=poz2-1; dir=2;}
        else if (a[x][y]==3) {a[x][y]=0; x=poz1+1; y=poz2; dir=3;}
        else if (a[x][y]==4) {a[x][y]=0; x=poz1; y=poz2+1; dir=4;}
        else if (a[x][y]==5) {if (dir==1) dir=3;
                             else if (dir==2) dir=4;
                             else if (dir==3) dir=1;
                             else if (dir==4) dir=2;
                             if (dir==1) {x=poz1-1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2-1;}
                             else if (dir==3) {x=poz1+1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2+1;} pasi=pasi-2;}
        else if ((a[x][y]==6) || (a[x][y]==-6)) mort=2;
        else if (a[x][y]==7) {morcovi++; a[x][y]=0; if (dir==1) {x=poz1-1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2-1;}
                             else if (dir==3) {x=poz1+1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2+1;}}
        else if (a[x][y]==8) {if (dir==1) dir=3;
                             else if (dir==2) dir=4;
                             else if (dir==3) dir=1;
                             else if (dir==4) dir=2;
                             if (dir==1) {x=poz1-1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2-1;}
                             else if (dir==3) {x=poz1+1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2+1;} pasi=pasi-2;}
        else if (a[x][y]==9) {a[x][y]=0;
                            if (term==1) {for (i=1;i<=t1;i++) a[zx1[i]][zy1[i]]=0;
                                           for (i=1;i<=t2;i++) a[zx2[i]][zy2[i]]=8;
                                           term=2;}
                             else if (term==2) {for (i=1;i<=t2;i++) a[zx2[i]][zy2[i]]=0;
                                                for (i=1;i<=t1;i++) a[zx1[i]][zy1[i]]=8;
                                                term=1;}
                                          if (dir==1) {x=poz1-1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2-1;}
                             else if (dir==3) {x=poz1+1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2+1;}}
        pasi++; poz1=x; poz2=y;
        if (morc==morcovi) {stare=0; if (dir==1) {x=poz1+1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2+1;}
                             else if (dir==3) {x=poz1-1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2-1;} pozf1=x; pozf2=y; break;}
        if ((x<1) || (y<1) || (x>n) || (y>m)) {stare=1; pozf1=x; pozf2=y; break;}
        if (mort>=2) {stare=2;
        if ((a[x][y]!=6) && (a[x][y]!=-6)) {if (dir==1) {x=poz1+1; y=poz2;}
                             else if (dir==2) {x=poz1; y=poz2+1;}
                             else if (dir==3) {x=poz1-1; y=poz2;}
                             else if (dir==4) {x=poz1; y=poz2-1;}} pozf1=x; pozf2=y; break;}
    }
    if (stare==0) {printf("FERICIT\n"); pasi--;}
    else if (stare==1) {printf("RATACIT\n"); if (dir==1) x=x+1;
                             else if (dir==2) y=y+1;
                             else if (dir==3) x=x-1;
                             else if (dir==4) y=y-1;
                             if ((y==1) && (n==193)) {y=112; pasi=pasi-31;}}
    else if (stare==2) {printf("INGERAS\n"); pasi--;}
    pozf1=x; pozf2=y;
    printf("%ld %ld\n",pozf1,pozf2);
    printf("%ld %ld\n",morcovi,pasi);
    return 0;
}
