#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long int n,ans;

    scanf("%d",&t);

    ans = 0;
    for(int i = 1; i <= t; i++ )
    {
        scanf("%lld",&n);

        ans = n * (n-1);
        ans = ans/2;

        if( ans % 2 == 0 )printf("Case %d: %lld\n",i,ans/2);
        else              printf("Case %d: %lld/2\n",i,ans);
    }
}
 // To iterate is human, to recurse divine.  - L. Peter Deutsch
