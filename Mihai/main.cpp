#include <iostream>

using namespace std;

int v[100],x[100],nr,i,j,n;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++) cin>>v[i];
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++) x[v[i]+v[j]]=1;
    nr=0;
    for (i=1;i<=n;i++) if (x[v[i]]==1) nr++;
    cout<<nr;
    return 0;
}
