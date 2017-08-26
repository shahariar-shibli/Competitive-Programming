#include<bits/stdc++.h>
using namespace std;

#define MX 105
#define inf 1<<28
int mat[MX][MX],dp[MX][MX];
int n;

void init()
{
    memset(dp,-1,sizeof(dp));
}

int call(int i, int j)
{
    if( i == n-1 && j == n-1 )dp[i][j] = mat[i][j];

    if( i == n || j == n )return -inf;

    if( dp[i][j] != -1 )return dp[i][j];

    int ret = -inf;

    ret = max(ret,call(i,j+1)+mat[i][j]);
    ret = max(ret,call(i+1,j)+mat[i][j]);

    return dp[i][j] = ret;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);

        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < i; j++ )
            {
                scanf("%d",&mat[i-j][j]);
            }
            scanf("%d",&mat[0][i]);
        }

        for( int i = 1; i < n; i++ )
        {
            scanf("%d",&mat[n-1][i]);

            for( int j = 0; i + j + 1 < n ; j++ )
            {
                scanf("%d",&mat[n - 2 - j][i+j+1]);
            }
        }


        /*
        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < n; j++ )
            {
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }
        */

        init();
        printf("Case %d: %d\n",kase,call(0,0));
    }
}
