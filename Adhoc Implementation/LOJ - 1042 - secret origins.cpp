#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull next_sim_one(ull x)
{
    ull smallest,ripples,ones;
    smallest = x & -x;
    ripples  = x + smallest;
    ones     = x ^ ripples;
    ones     = (ones >> 2)/smallest;
    return ripples|ones;
}

int main()
{
    int t;
    ull n;

    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld",&n);
        printf("Case %d: %u\n",kase,next_sim_one(n));
    }
}
//https://www.slideshare.net/gkumar007/bits-next-higher-presentation
