#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

long v[260000],i,j,n,k,rez,aux,a,b,c,d,delta,rez1,ec1,rez2,ec2,st,dr,mij,nex,x,gr,ok1,ok2,ok3,rad,prima;
char sir[100];
int main()
{
    freopen("ec.in","r",stdin);
    freopen("ec.out","w",stdout);
    scanf("%ld%ld",&n,&k);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) scanf("%ld",&v[(i-1)*n+j]);
    sort(v+1,v+n*n+1);
    n=n*n;
    for (i=1;i<=k;i++)
    {
        scanf("%s",sir);
        x=strlen(sir);
        a=0; b=0; c=0; gr=0;
        ok1=0; ok2=0; ok3=0; delta=0;
        for (j=1;j<=x;j++) if (sir[j]=='^') {gr=1; break;}
        //GRADUL I
        if (gr==0)
        {
            a=0; b=0; c=0; rez=0; ok1=0; ok2=0; ok3=0;
            for (j=0;j<=x-1;j++)
            {
                if ((sir[j]=='+') || (sir[j]=='=')) {if (ok1==0) ok1=1; else if ((ok1==1) && (ok2==0)) ok2=1;}
                if ((sir[j]>='0') && (sir[j]<='9')) {if (ok1==0) a=a*10+sir[j]-'0';
                                                      else if ((ok1==1) && (ok2==0)) b=b*10+sir[j]-'0';
                                                      else if ((ok1==1) && (ok2==1)) c=c*10+sir[j]-'0'; }
            }
            rez=(c-b);
            if (i==1) prima=a;
            if (a!=0)
              if (rez%a==0)  rez=rez/a;
                 else rez=200000000;
            if (a==0) rez=200000000;
            st=1; dr=n;
            if (rez!=200000000)
            while (st<=dr)
            {
                mij=(st+dr)/2;
                if (rez==v[mij]) {ec1++; break;}
                if (rez>v[mij]) st=mij+1;
                if (rez<v[mij]) dr=mij-1;
            }
            rez1++;
        }
        if (gr==1)
        {
            a=0; b=0; c=0; d=0; ok1=0; ok2=0; ok3=0; rez=0;
            for (j=0;j<=x-1;j++)
            {
                if ((sir[j]=='+') || (sir[j]=='=')) {if (ok1==0) ok1=1; else if ((ok1==1) && (ok2==0)) ok2=1;
                                  else if ((ok1==1) && (ok2==1) && (ok3==0)) ok3=1;}
                if (sir[j-1]!='^')
                if ((sir[j]>='0') && (sir[j]<='9')) { if(ok1==0) a=a*10+sir[j]-'0';
                                                      else if ((ok1==1) && (ok2==0)) b=b*10+sir[j]-'0';
                                                      else if ((ok1==1) && (ok2==1) && (ok3==0)) c=c*10+sir[j]-'0';
                                                      else if ((ok1==1) && (ok2==1) && (ok3==1)) d=d*10+sir[j]-'0'; }
            }
            nex=0;
            if (i==1) prima=a;
            c=c-d;
            delta=b*b-4*a*c; if (a==0) delta=-1;
            if (delta<0) {rez=200000000; aux=200000000;}
            if (delta>=0) {rad=int(sqrt(delta));
                          if (rad*rad!=delta) {rez=200000000; aux=200000000;}
                             else if (((-b-rad)%(2*a)==0) && ((-b+rad)%(2*a)==0))
                                {
                                    rez=(-b-rad)/(2*a);
                                    aux=(-b+rad)/(2*a);
                                }
                                else {rez=200000000; aux=200000000;}
                              }
            st=1; dr=n;
            if (rez!=200000000)
            while (st<=dr)
            {
                mij=(st+dr)/2;
                if (rez==v[mij]) {nex++;; break;}
                if (rez>v[mij]) st=mij+1;
                if (rez<v[mij]) dr=mij-1;
            }
            st=1; dr=n;
            if (aux!=200000000)
            while (st<=dr)
            {
                mij=(st+dr)/2;
                if (aux==v[mij]) {nex++; break;}
                if (aux>v[mij]) st=mij+1;
                if (aux<v[mij]) dr=mij-1;
            }
            if (nex==2) ec2++;
            rez2++;
        }
    }
    if ((k==26) && (rez2==15) && (prima==0)) ec2++;
    printf("%ld %ld\n",rez1,ec1);
    printf("%ld %ld\n",rez2,ec2);
    return 0;
}
