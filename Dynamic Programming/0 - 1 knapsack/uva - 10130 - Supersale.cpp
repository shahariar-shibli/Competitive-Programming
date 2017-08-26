#include<bits/stdc++.h>
using namespace std;

#define MX 10005

int DP[MX][35],weight[MX],price[MX];
int capacity,n;

void init()
{
   memset(DP,-1,sizeof(DP));
}

int knapsack(int i,int w)
{
    if( i == n+1 )return 0;   //base case

    if( DP[i][w] != -1 )return DP[i][w];   // already saved in table so return

    int profit1,profit2;
    profit1 = profit2 = 0;

    if( w + weight[i] <= capacity )
    {
        profit1 = price[i] + knapsack(i+1,w+weight[i]);   // i is taken now check can we take i+1
    }
    //else profit1 = 0;

    profit2 = knapsack(i+1,w);   // if we can't take i+1

    DP[i][w] = max(profit1,profit2);   // maximum profit save in table.
    return DP[i][w];

}

int main()
{
   int t,g,sum;
   scanf("%d",&t);

   for(int i = 1; i <= t; i++ )
   {
       scanf("%d",&n);
       //init();

       for(int j = 1; j<= n; j++ )
       {
           scanf("%d %d",&price[j],&weight[j]);
       }
       scanf("%d",&g);

       sum = 0;
       for(int j = 1; j <= g; j++ )
       {
           init();
           scanf("%d",&capacity);
           sum += knapsack(1,0);
       }

        printf("%d\n",sum);
   }

}

