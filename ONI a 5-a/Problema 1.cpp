#include <fstream>

using namespace std;
ifstream fin("2048.in");
ofstream fout("2048.out");
int v[10000],x[10000],n,m,k,i,j,gata,exista,fuz,maxfuz;
char c[10000];
int main ()
{
 fin>>n>>m;
 for (i=1;i<=n;i++)
   fin>>v[i];
 gata=1; i=1; exista=0; fuz=0; maxfuz=0;
 while ((gata==1) && (i<=m) && (exista!=2048))
   {
     fin>>c[i];
     gata=0; fuz=0;
     if (c[i]=='S')
       {
          for (j=1;j<=n-1;j++)
            if (v[j]==v[j+1])
                  {
                      v[j]=v[j]*2;
                      v[j+1]=0;
                      gata=1;
                      fuz++;
                  }
          k=0;
          for (j=1;j<=n;j++)
            if (v[j]!=0)
              {
                  k++;
                  x[k]=v[j];
              }
          n=k;
          for (j=1;j<=n;j++) v[j]=x[j];
       }
     if (c[i]=='D')
       {
          for (j=n;j>=2;j--)
            if (v[j]==v[j-1])
                  {
                      v[j]=v[j]*2;
                      v[j-1]=0;
                      gata=1;
                      fuz++;
                  }
          k=0;
          for (j=n;j>=1;j--)
            if (v[j]!=0)
              {
                  k++;
                  x[n-k+1]=v[j];
              }
          n=k;
          for (j=1;j<=n;j++) v[j]=x[j];
       }
     i++;
     for (j=1;j<=n;j++)  if (exista<v[j]) exista=v[j];
     if (fuz>maxfuz) maxfuz=fuz;
   }
 fout<<i<<'\n';
 fout<<exista<<'\n';
 fout<<maxfuz<<'\n';
 fin.close();
 fout.close();
 return 0;
}
