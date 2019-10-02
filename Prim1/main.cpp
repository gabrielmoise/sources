#include <iostream>

using namespace std;

int i,n,prim;
int main()
{
    cin>>n;
    prim=1;
    for (i=2;i<=(n/2);i++) if (n%i==0) prim=0;
    if (prim==0) cout<<"Nu este prim.";
       else cout<<"Este prim.";
    return 0;
}
