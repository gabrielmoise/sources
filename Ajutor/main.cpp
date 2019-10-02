#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s1[1010000], s2[1000000];

int main()
{
    freopen("ajutor.in","r",stdin);
    freopen("ajutor.out","w",stdout);
    gets(s1); gets(s2);
    if (s1!=s2) printf("NU");
        else printf("DA");
    return 0;
}
