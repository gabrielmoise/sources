#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100];
long i,n,ok,nr1,nr2,nr3,nr4,a,b,c;
int main()
{
    freopen("peculiar.in","r",stdin);
    freopen("peculiar.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",&s[0]);
        if (s[0]=='0') nr1=0;
        if (s[0]=='1') nr1=1;
        if (s[0]=='2') nr1=2;
        if (s[0]=='3') nr1=3;
        if (s[0]=='4') nr1=4;
        if (s[0]=='5') nr1=5;
        if (s[0]=='6') nr1=6;
        if (s[0]=='7') nr1=7;
        if (s[0]=='8') nr1=8;
        if (s[0]=='9') nr1=9;

        if (s[1]=='0') nr2=0;
        if (s[1]=='1') nr2=1;
        if (s[1]=='2') nr2=2;
        if (s[1]=='3') nr2=3;
        if (s[1]=='4') nr2=4;
        if (s[1]=='5') nr2=5;
        if (s[1]=='6') nr2=6;
        if (s[1]=='7') nr2=7;
        if (s[1]=='8') nr2=8;
        if (s[1]=='9') nr2=9;

        if (s[3]=='0') nr3=0;
        if (s[3]=='1') nr3=1;
        if (s[3]=='2') nr3=2;
        if (s[3]=='3') nr3=3;
        if (s[3]=='4') nr3=4;
        if (s[3]=='5') nr3=5;
        if (s[3]=='6') nr3=6;
        if (s[3]=='7') nr3=7;
        if (s[3]=='8') nr3=8;
        if (s[3]=='9') nr3=9;

        if (s[4]=='0') nr4=0;
        if (s[4]=='1') nr4=1;
        if (s[4]=='2') nr4=2;
        if (s[4]=='3') nr4=3;
        if (s[4]=='4') nr4=4;
        if (s[4]=='5') nr4=5;
        if (s[4]=='6') nr4=6;
        if (s[4]=='7') nr4=7;
        if (s[4]=='8') nr4=8;
        if (s[4]=='9') nr4=9;

        a=nr1*10+nr2; b=nr3*10+nr4; c=nr4*10+nr3;
        ok=0;
        if (b==0) ok=1;
        if (a==b) ok=1;
        if ((a==c) || (a==c*10) || (a*10==c) || (a*10==c*10)) ok=1;
        if (((a==1) && (b==23)) || ((a==12) && (b==34)) || ((a==23) && (b==45))) ok=1;
        if (((a==10) && (b==24)) || ((a==20) && (b==48)))ok=1;
        if ((a>=24) || (b>=60) || (a<0) || (b<0)) ok=0;
        if (ok==0) printf("NO\n");
        else if (ok==1) printf("YES\n");
    }
    return 0;
}
