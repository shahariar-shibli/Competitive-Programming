#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
vector<lli>x,y;

int main()
{
    int t;
    lli a,b,sum,n,cnt;

    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld %lld",&n,&cnt);

        for(int i = 0; i < n; i++ )
        {
            scanf("%lld",&a);
            x.push_back(a);
        }

        for(int i = 0; i < n; i++ )
        {
            scanf("%lld",&a);
            b = a - x[i];
            y.push_back(b);
        }

        sort(y.begin(),y.end());

        lli profit = 0;
        for(int i = 0; i < n; i++ )
        {
            if( y[i] <= 0 && cnt > 0 )cnt--;
            else   profit += y[i];
        }

        if( profit > 0 )printf("Case %d: %lld\n",kase,profit);
        else            printf("Case %d: No Profit\n",kase);

        x.clear();
        y.clear();
    }
}
