#include<bits/stdc++.h>
using namespace std;

#define MX 25
#define inf 1<<28
int weight[MX][MX],dp[MX][MX];
int n;

void init()
{
    memset(dp,-1,sizeof(dp));
}

//i = now, w = prev
int knapsack(int i, int w)
{
    if( i == n + 1 )return 0;

    if( dp[i][w] != -1 )return dp[i][w];

    int ret = inf;

    for(int j = 1; j <= 3; j++ )
    {
        if( j != w )
        {
            ret = min(ret, weight[i][j] + knapsack(i+1, j));
        }
    }

    return dp[i][w] = ret;

}


int main()
{
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);

        for(int i = 1; i <= n; i++ )
        {
            scanf("%d %d %d",&weight[i][1],&weight[i][2],&weight[i][3]);
        }

        init();
        printf("Case %d: %d\n",kase,knapsack(1,0));
    }
}
