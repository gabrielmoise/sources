#include <iostream>

using namespace std;

int n,sw;
char x;
int main()
{
    cout<<"caracter="; cin>>x;
    n=x;
    if (48<=n && n<=57)
        sw=1;
        else
        sw=0;
    if (sw) cout<<"DA";
      else  cout<<"NU";
    return 0;
}
