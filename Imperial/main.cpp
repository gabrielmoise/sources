#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long i,j,k,x,y,z,v;

int main()
{
    freopen("imperial.in","r",stdin);
    freopen("imperial.out","w",stdout);
    scanf("%ld%ld",&x,&y);
    for(i=x;i<=x+3;i++)
        {v=i;

    for (j=1;j<=y;j++) v=v*i;
    printf("%ld ",v);}
    return 0;
}
