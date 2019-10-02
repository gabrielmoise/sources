#include <iostream>
#include <cstdio>

using namespace std;

long s[10002],v[50002];
long c,n,x,y,i,j;

int main()
{
    freopen("rafturi.in","r",stdin);
    freopen("rafturi.out","w",stdout);
    scanf("%ld%ld",&c,&n);
    for (i=1;i<=n;i++)
    {
        scanf("%ld%ld",&x,&y);
        if (v[x]<y) v[x]=y;
    }
    s[0]=0;
	for (i=1;i<=c;i++)
	{
		s[i]=100000000;
		x=v[i];
		if (s[i-1]+x<s[i]) s[i]=s[i-1]+x;
		for (j=i-1;j>=i-2;j--) if (j>0)
		{
			if (x<v[j]) x=v[j];
			if (s[j-1]+x<s[i]) s[i]=s[j-1]+x;
		}
	}
	printf("%ld\n",s[c]);
	return 0;
}
