#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string S,T;

    scanf("%d",&t);
    getchar();

    for(int kase = 1; kase <= t; kase++ )
    {
        cin>>S>>T;

        int sone,szero,tone,tzero,ans;
        sone = szero = tone = tzero = ans = 0;

        for(int i = 0; i < S.size(); i++ )
        {
            if( S[i] == '1' )    sone++;
            else if( S[i] == '0')szero++;
            else ans++;

            if( T[i] == '1' )tone++;
            else             tzero++;
        }

        int ZERO,ONE;
        ZERO = ONE = 0;

        for(int i = 0; i < S.size(); i++ )
        {
            if( S[i] == T[i] )continue;
            else if( S[i] == '0' && T[i] == '1' )ZERO++;
            else if( S[i] == '1' && T[i] == '0' )ONE++;
        }

        ans = ans + max(ZERO,ONE);

        if( sone > tone )printf("Case %d: -1\n",kase);
        else             printf("Case %d: %d\n",kase,ans);
    }
}
