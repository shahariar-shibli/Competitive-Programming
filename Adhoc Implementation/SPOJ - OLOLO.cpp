#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    ll x;
    while(scanf("%d",&n) == 1 )
    {
        ll ans = 0;
        for(int i = 0; i < n; i++ )
        {
            scanf("%lld",&x);
            ans = ans ^ x;
        }
        printf("%lld\n",ans);
    }
}
