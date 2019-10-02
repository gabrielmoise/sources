#include <iostream>

using namespace std;

int n,p,i,aux,c;
int main()
{
    cin>>n>>p;
    //c=numar de cifre ale lui n
    aux=n;
    while (aux>0)
    {
        c=c+1;
        aux=aux/10;
    }
    for (i=1;i<=p;i++) n=(n%10)*pow(10.0,c-1)+(n/10);
    cout<<n;
    return 0;
}
