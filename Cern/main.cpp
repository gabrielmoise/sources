#include <iostream>
#include <cstdio>

using namespace std;

long long n;
long semn,cerc,poz,aux;
char x;

int main()
{
    freopen("cern.in","r",stdin);
    freopen("cern.out","w",stdout);
    scanf("%c",&x);
    scanf("%ld%lld",&semn,&n);
    n=n%1080;
    poz=0; cerc=0;
    if (x=='A') {poz=0; cerc=1;}
    else if (x=='B') {poz=60; cerc=1;}
    else if (x=='C') {poz=120; cerc=2;}
    else if (x=='D') {poz=180; cerc=2;}
    else if (x=='E') {poz=240; cerc=3;}
    else if (x=='F') {poz=300; cerc=3;}
    aux=1;
    while (aux<=n)
    {
        if ((poz==180) && (cerc==1)) {poz=0; cerc=2; semn=semn*(-1);}
        else if ((poz==240) && (cerc==1)) {poz=60; cerc=3; semn=semn*(-1);}
        else if ((poz==0) && (cerc==2)) {poz=180; cerc=1; semn=semn*(-1);}
        else if ((poz==300) && (cerc==2)) {poz=120; cerc=3; semn=semn*(-1);}
        else if ((poz==120) && (cerc==3)) {poz=300; cerc=2; semn=semn*(-1);}
        else if ((poz==60) && (cerc==3)) {poz=240; cerc=1; semn=semn*(-1);}
        aux=aux+1;
        if (semn==1) poz=poz+1;
            else if (semn==-1) poz=poz-1;
        if (poz<0) poz=poz+360;
        if (poz>=360) poz=poz-360;
    }
    printf("%ld %ld",poz,cerc);
    return 0;
}
