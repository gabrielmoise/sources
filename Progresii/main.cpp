#include <iostream>
#include <cstdio>

using namespace std;

long n,s,start,i;
int main()
{
    freopen("noname3.in","r",stdin);
    freopen("noname3.out","w",stdout);
    scanf("%ld%ld",&n,&s);
    start=1; s-=(n*(n+1))>>1;
    if (s<0) { printf("-1"); return 0;}
    start += s / n; s %= n; s = n-s;
    for(i=1;i<=n;i++){
        printf("%ld ",start+i-1);
        if(i == s) start++;
    }
    return 0;
}
