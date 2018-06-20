#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

int main()
{
    lli n;
    while( scanf("%lld",&n) == 1  )
    {
        if( n == 0 )break;
        n++;
        if( n & (n-1) )printf("Alice\n");
        else printf("Bob\n");
    }
}
