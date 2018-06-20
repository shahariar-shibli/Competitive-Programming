#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;

    scanf("%d",&t);
    getchar();

    for(int kase = 1; kase <= t; kase++ )
    {
        cin>>s;

        int sum,ans;
        sum = ans = 0;

        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == 'O' )
            {
                sum++;
                ans += sum;
            }
            else sum = 0;
        }

        printf("%d\n",ans);
    }
}
