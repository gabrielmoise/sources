#include <iostream>
#include <cstdio>

using namespace std;

long n,s,y,i;
long long x;
int main()
{
    freopen("noname3.in","r",stdin);
    freopen("noname3.out","w",stdout);
    scanf("%ld%ld",&n,&s);
    x=(n*(n+1))/2;
    if (x>s) printf("%ld",-1);
    if (x<=s)
    {
        y=s-x;
        for (i=1;i<=n-(y%n);i++) printf("%ld ",i+(y/n));
        for (i=n-(y%n)+1;i<=n;i++) printf("%ld ",i+(y/n)+1);
    }
    return 0;
}
