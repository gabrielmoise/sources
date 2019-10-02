#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long v[21],a[21],i,j,x,p,s,dif,n,ok;
char sir[200];
int main()
{
    freopen("7segmente.in","r",stdin);
    freopen("7segmente.out","w",stdout);
    gets(sir);
    x=strlen(sir);
    for (i=0;i<x;i++) if (sir[i]!=' ') v[i+1]=int(sir[i])-int('0');
                          else break;
    n=i; p=0;
    for (j=i+1;j<x;j++) {if (sir[j]=='0') p=p*10+0;
                        else if (sir[j]=='1') p=p*10+1;
                        else if (sir[j]=='2') p=p*10+2;
                        else if (sir[j]=='3') p=p*10+3;
                        else if (sir[j]=='4') p=p*10+4;
                        else if (sir[j]=='5') p=p*10+5;
                        else if (sir[j]=='6') p=p*10+6;
                        else if (sir[j]=='7') p=p*10+7;
                        else if (sir[j]=='8') p=p*10+8;
                        else if (sir[j]=='9') p=p*10+9;}
    a[1]=2; a[2]=5; a[3]=5; a[4]=4; a[5]=5; a[6]=6; a[7]=3; a[8]=7; a[9]=6;
    s=0;
    for (i=1;i<=n;i++) s=s+a[v[i]];
    printf("%ld ",s);
    if (p>=s) for (i=1;i<=n;i++) printf("%ld",v[i]);
    if (p<s)
    {
        dif=s-p;
        for (i=n;i>=1;i--) if (dif>0) if (a[v[i]]-a[1]<=dif) {dif=dif-(a[v[i]]-a[1]); v[i]=1;}
                                          else { ok=0;
                                                for (j=v[i]-1;j>=1;j--) {if (a[v[i]]-a[j]>=dif) {v[i]=j; ok=1;} break;}
                                               dif=0; if (ok==0) v[i]=1; break;}
    }
    s=0;
    for (i=1;i<=n;i++) s=s+a[v[i]];
    if (s>p) while (s>p) {n=n-1; s=s-2;}
    for (i=1;i<=n;i++) printf("%ld",v[i]);
    return 0;
}
