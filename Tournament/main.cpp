#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    freopen("tournament.in","r",stdin);
    freopen("tournament.out","w",stdout);
    scanf("%s",s[0]);
    i=0;
    while (s[i]!=' ') {a=a+s[i]; i++;}
    i=i+1;
    while (s[i]!=' ') {b=b+s[i]; i++;}
    i=i+1;
    if (s[i]=='0') v[1]=v[1]+0;
    if ((s[i]=='1') && (s[i+1]==' ')) v[1]=v[1]+1;
    if ((s[i]=='1') && (s[i+1]=='0')) v[1]=v[1]+10;
    if (s[i]=='2') v[1]=v[1]+2;
    if (s[i]=='3') v[1]=v[1]+3;
    if (s[i]=='4') v[1]=v[1]+4;
    if (s[i]=='5') v[1]=v[1]+5;
    if (s[i]=='6') v[1]=v[1]+6;
    if (s[i]=='7') v[1]=v[1]+7;
    if (s[i]=='8') v[1]=v[1]+8;
    if (s[i]=='9') v[1]=v[1]+9;
    x=s[i]; if (s[i+1]=='0') x=x+'0';
    i=i+2;
    if (s[i]=='0') v[2]=v[2]+0;
    if ((s[i]=='1') && (s[i+1]==' ')) v[2]=v[2]+1;
    if ((s[i]=='1') && (s[i+1]=='0')) v[2]=v[2]+10;
    if (s[i]=='2') v[2]=v[2]+2;
    if (s[i]=='3') v[2]=v[2]+3;
    if (s[i]=='4') v[2]=v[2]+4;
    if (s[i]=='5') v[2]=v[2]+5;
    if (s[i]=='6') v[2]=v[2]+6;
    if (s[i]=='7') v[2]=v[2]+7;
    if (s[i]=='8') v[2]=v[2]+8;
    if (s[i]=='9') v[2]=v[2]+9;
    y=s[i]; if (s[i+1]=='0') y=y+'0';
    if ((x>y) || ((x=='10') && (y!=x))) p[1]=p[1]+3;
    if ((x<y) || ((y=='10') && (y!=x))) p[2]=p[2]+3;
    if (x==y) {p[1]++; p[2]++;}
    ////////////////////////////////////////////////////////////////////////////
    scanf("%s",s[0]);
    i=0;
    while (s[i]!=' ') {c=c+s[i]; i++;}
    i=i+1;
    while (s[i]!=' ') {d=d+s[i]; i++;}
    i=i+1;
    if (s[i]=='0') v[1]=v[1]+0;
    if ((s[i]=='1') && (s[i+1]==' ')) v[1]=v[1]+1;
    if ((s[i]=='1') && (s[i+1]=='0')) v[1]=v[1]+10;
    if (s[i]=='2') v[1]=v[1]+2;
    if (s[i]=='3') v[1]=v[1]+3;
    if (s[i]=='4') v[1]=v[1]+4;
    if (s[i]=='5') v[1]=v[1]+5;
    if (s[i]=='6') v[1]=v[1]+6;
    if (s[i]=='7') v[1]=v[1]+7;
    if (s[i]=='8') v[1]=v[1]+8;
    if (s[i]=='9') v[1]=v[1]+9;
    x=s[i]; if (s[i+1]=='0') x=x+'0';
    i=i+2;
    if (s[i]=='0') v[2]=v[2]+0;
    if ((s[i]=='1') && (s[i+1]==' ')) v[2]=v[2]+1;
    if ((s[i]=='1') && (s[i+1]=='0')) v[2]=v[2]+10;
    if (s[i]=='2') v[2]=v[2]+2;
    if (s[i]=='3') v[2]=v[2]+3;
    if (s[i]=='4') v[2]=v[2]+4;
    if (s[i]=='5') v[2]=v[2]+5;
    if (s[i]=='6') v[2]=v[2]+6;
    if (s[i]=='7') v[2]=v[2]+7;
    if (s[i]=='8') v[2]=v[2]+8;
    if (s[i]=='9') v[2]=v[2]+9;
    y=s[i]; if (s[i+1]=='0') y=y+'0';
    if ((x>y) || ((x=='10') && (y!=x))) p[3]=p[3]+3;
    if ((x<y) || ((y=='10') && (y!=x))) p[4]=p[4]+3;
    if (x==y) {p[3]++; p[4]++;}
    /////////////////////////////////////////////////////////////////////
    for (j=3;j<=6;j++)
    {
    scanf("%s",s[0]);
    i=0;
    while (s[i]!=' ') {a1=a1+s[i]; i++;}
    i=i+1;
    while (s[i]!=' ') {b1=b1+s[i]; i++;}
    i=i+1;

    if (s[i]=='0') v[1]=v[1]+0;
    if ((s[i]=='1') && (s[i+1]==' ')) v[1]=v[1]+1;
    if ((s[i]=='1') && (s[i+1]=='0')) v[1]=v[1]+10;
    if (s[i]=='2') v[1]=v[1]+2;
    if (s[i]=='3') v[1]=v[1]+3;
    if (s[i]=='4') v[1]=v[1]+4;
    if (s[i]=='5') v[1]=v[1]+5;
    if (s[i]=='6') v[1]=v[1]+6;
    if (s[i]=='7') v[1]=v[1]+7;
    if (s[i]=='8') v[1]=v[1]+8;
    if (s[i]=='9') v[1]=v[1]+9;
    x=s[i]; if (s[i+1]=='0') x=x+'0';
    i=i+2;
    if (s[i]=='0') v[2]=v[2]+0;
    if ((s[i]=='1') && (s[i+1]==' ')) v[2]=v[2]+1;
    if ((s[i]=='1') && (s[i+1]=='0')) v[2]=v[2]+10;
    if (s[i]=='2') v[2]=v[2]+2;
    if (s[i]=='3') v[2]=v[2]+3;
    if (s[i]=='4') v[2]=v[2]+4;
    if (s[i]=='5') v[2]=v[2]+5;
    if (s[i]=='6') v[2]=v[2]+6;
    if (s[i]=='7') v[2]=v[2]+7;
    if (s[i]=='8') v[2]=v[2]+8;
    if (s[i]=='9') v[2]=v[2]+9;
    y=s[i]; if (s[i+1]=='0') y=y+'0';
    if ((x>y) || ((x=='10') && (y!=x))) p[1]=p[1]+3;
    if ((x<y) || ((y=='10') && (y!=x))) p[2]=p[2]+3;
    if (x==y) {p[1]++; p[2]++;}
    }
}
