#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
lli arr[22];
vector<int>V;

void pre_cal()
{
    arr[0] = 1;
    for(int i = 1; i < 21; i++ )arr[i] = arr[i-1]*i;
}

int main()
{
    pre_cal();

    int t;
    lli n;
    scanf("%d",&t);

    for(int  kase = 1; kase <= t; kase++ )
    {
        scanf("%lld",&n);

        int pos = 0;
        for(int i = 20; i >= 0; i-- )
        {
            //if( n == 0 )break;

            if( arr[i] <= n )
            {
                V.push_back(i);
                n = n - arr[i];
                //cout<<n<<endl;
            }
        }
        printf("Case %d: ",kase);
        if( n != 0 )printf("impossible\n");
        else
        {
            sort(V.begin(),V.end());
            for(int i = 0; i < V.size(); i++ )
            {
                if( i > 0 && i < V.size() )printf("+");
                printf("%d!",V[i]);
            }
            printf("\n");
        }
        V.clear();
    }
}
