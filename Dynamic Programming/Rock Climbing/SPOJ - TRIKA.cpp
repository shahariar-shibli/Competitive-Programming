#include<bits/stdc++.h>
using namespace std;

#define MX 30
#define inf 1<<28
int n,m;
int matrix[MX][MX],dp[MX][MX];

int call(int i,int j)
{
        if(i==n-1 && j== m-1) return dp[i][j] = matrix[n-1][m-1];
        if(i==n|| j==m) return inf;
        if( dp[i][j] != -1 )return dp[i][j];


        int ret = inf;


        ret = min(ret,call(i,j+1)+matrix[i][j]);
        ret = min(ret,call(i+1,j)+matrix[i][j]);

        return dp[i][j] = ret;

}


int main()
{
    while(scanf("%d %d",&n,&m) == 2)
    {
        int x,y;
        scanf("%d %d",&x,&y);

        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < m; j++ )
            {
                scanf("%d",&matrix[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));

        int ans = (2*matrix[x-1][y-1])-call(x-1,y-1);

        if( ans >= 0 )printf("Y %d\n",ans);
        else          printf("N\n");

        //cout<<(2*matrix[x-1][y-1])-call(x-1,y-1)<<endl;

    }

}
