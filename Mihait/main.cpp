#include <iostream>

using namespace std;

int v[100],n,i,j,ok,aux;

int main()
{
    while (1==1) i++;
    cin>>n;
    for (i=1;i<=n;i++) cin>>v[i];
    ok=1;
    while (ok==1)
    {
        ok=0;
        for (i=1;i<=n;i++)  if (v[i]%2==0) for (j=i+1;j<=n;j++)
                            if ((v[j]%2==0) && (v[i]>v[j])) {ok=1; aux=v[i]; v[i]=v[j]; v[j]=aux;}
    }
    for (i=1;i<=n;i++) cout<<v[i]<<" ";
    return 0;
}
