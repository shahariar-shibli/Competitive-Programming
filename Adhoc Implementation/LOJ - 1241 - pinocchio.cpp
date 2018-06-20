#include<bits/stdc++.h>
using namespace std;

vector<int>V;

int main()
{
    int t,n,x;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);
        bool ok = false;
        for(int i = 0; i < n ; i++ )
        {
            scanf("%d",&x);

            if( x != 2 && !ok )
            {
                V.push_back(2);
                V.push_back(x);
                ok = true;
            }
            else V.push_back(x);
        }
        int ans,sum;
        sum = 0;
        for(int i = 1; i < V.size(); i++ )
        {
            int y = V[i] - V[i-1];
            ans = 0;
            ans = y/5;
            if( y % 5 != 0 )ans++;
            sum += ans;
        }
        printf("Case %d: %d\n",kase,sum);
        V.clear();
    }
}
