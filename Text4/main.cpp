#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long n,nrf,nr,i;
char sir[1100];
char s[1200];
int main()
{
    freopen("text4.in","r",stdin);
    freopen("text4.out","w",stdout);
    scanf("%ld\n",&n);
    nrf=-1;
    while (sir!="") {gets(sir);
    nr=strlen(sir);
    for (i=nrf+1;i<=nrf+nr;i++) s[i]=sir[i-nrf-1];
    nrf=nrf+nr;
    }
    printf("%s",s);
    return 0;
}
