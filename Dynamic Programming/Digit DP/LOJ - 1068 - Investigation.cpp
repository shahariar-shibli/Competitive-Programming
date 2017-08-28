#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
lli dp[12][82][82];
int k;

lli F(lli pos, lli sum, lli digsum)
{
    if( pos == 0 )
    {
        if( sum == 0 && digsum == 0 )return 1;
        else return 0;
    }

    if(dp[pos][sum][digsum] != -1)return dp[pos][sum][digsum];

    lli ans = 0;
    for(int i = 0; i <= 9; i++ )
    {
        ans += F(pos-1,(sum*10+i)%k, (digsum+i)%k);
    }

    return dp[pos][sum][digsum] = ans;
}

lli solve(lli x)
{
    lli res = 0;

    char cad[20];
    sprintf(cad,"%lld",x);
	int len = strlen(cad);

    lli sum = 0;
    lli digsum = 0;

    lli qued = len;
    for(int i = 0; i < len; i++ )
    {
        qued--;
        lli d = cad[i] - '0';
        //cout<<d<<endl;

        for(int j = 0; j < d; j++ )
        {
            res += F(qued,(sum*10+j)%k, (digsum+j)%k);
        }

        //cout<<res<<endl;

        sum = (sum*10+d)%k;
        digsum = (digsum+d)%k;
    }
    //cout<<sum<<" "<<digsum<<endl;
    return res+F(0,sum%k,digsum%k);
}

int main()
{
    //freopen("output6.txt","w",stdout);
    lli A,B;
    int t;

    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld %lld %d",&A,&B,&k);

        if( k >= 82 )printf("Case %d: 0\n",kase);
        else
        {
            memset(dp,-1,sizeof(dp));
            printf("Case %d: %d\n",kase,solve(B)-solve(A-1));
        }
    }

}
//http://codeforces.com/blog/entry/8221

