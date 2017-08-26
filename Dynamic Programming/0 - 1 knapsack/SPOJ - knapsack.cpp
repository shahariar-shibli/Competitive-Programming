#include<bits/stdc++.h>
using namespace std;

#define MX 2005

int DP[MX][MX],weight[MX],price[MX];
int n,capacity;

void init()
{
    memset(DP,-1,sizeof(DP));
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

   while( scanf("%d %d",&capacity,&n) == 2 )
   {
        init();
        for(int i = 1; i <= n; i++ )
        {
            scanf("%d %d",&weight[i],&price[i]);
        }

         printf("%d\n",knapsack(1,0));
   }

}

