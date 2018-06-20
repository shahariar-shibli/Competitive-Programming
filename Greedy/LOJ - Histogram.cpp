#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 30005
lli H[MX];

lli Histogram(int n)
{
    stack<lli>stk;

    int pos = 0;
    lli Ans = 0, top , Area_with_top;

    while( pos < n )
    {
        if( stk.empty() || H[stk.top()] <= H[pos] )stk.push(pos++);
        else
        {
            top = stk.top();
            stk.pop();

            Area_with_top = H[top] * ( stk.empty()?pos : pos - stk.top() - 1);
            Ans = max(Ans,Area_with_top);
        }
    }

    while(!stk.empty())
    {
        top = stk.top();
        stk.pop();

        Area_with_top = H[top] * ( stk.empty()?pos : pos - stk.top() - 1);
        Ans = max(Ans,Area_with_top);
    }
    return Ans;
}


int main()
{
    int t,n;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);

        for(int i = 0; i < n; i++ )
        {
            scanf("%lld",&H[i]);
        }

        printf("Case %d: %lld\n",kase,Histogram(n));

    }
}
