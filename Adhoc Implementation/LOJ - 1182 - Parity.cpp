#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n,cnt;
    scanf("%d",&t);

    for(int i = 1; i <= t; i++ )
    {
        scanf("%d",&n);
        cnt = 0;
        while( n > 0 )
        {
            //cout<<22<<endl;
            if( (n % 2) != 0 )
            {
                cnt++;
                n = n/2;
            }
            else
            {
                n = n /2;
            }
        }

        if( (cnt % 2) == 0 )printf("Case %d: even\n",i);
        else printf("Case %d: odd\n",i);
    }

}
