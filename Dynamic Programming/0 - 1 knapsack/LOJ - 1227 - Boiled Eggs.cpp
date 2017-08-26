#include<bits/stdc++.h>
using namespace std;

#define MX 35

int DP[MX][MX],weight[MX],price[MX];
int n,capacity;

void init()
{
    memset(DP,-1,sizeof(DP));
    for(int i = 1; i <= n; i++ )price[i] = 1;
}

int knapsack(int i , int w)
{
    if( i == n+1 )return 0;

    if( DP[i][w] != -1 )return DP[i][w];

    int value1,value2;

    value1 = value2 = 0;

    if( w + weight[i] <= capacity )
    {
        value1 = price[i] + knapsack(i+1,w+weight[i]);
    }

    value2 = knapsack(i+1,w);

    DP[i][w] = max(value1,value2);
    return DP[i][w];

}

int main()
{
    int t,p;
    scanf("%d",&t);

    for(int k = 1; k <= t; k++ )
    {
        scanf("%d %d %d",&n,&p,&capacity);

        init();

        for(int i = 1; i <= n; i++ )
        {
            scanf("%d",&weight[i]);
        }

         printf("Case %d: %d\n",k,min(knapsack(1,0),p));

    }

}
