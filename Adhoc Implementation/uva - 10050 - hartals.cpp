#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,p,arr[105];
    scanf("%d",&t);

    for(int i = 1; i <= t; i++ )
    {
        scanf("%d %d",&n,&p);

        for(int j = 1; j <= p; j++ )
        {
            scanf("%d",&arr[j]);
        }

        bool found;
        int cnt = 0;
        for(int k = 1; k <= n; k++ )
        {
            if( k % 7 == 6 || k % 7 == 0 )continue;

            found = false;

            for(int a = 1; a <= p ; a++ )
            {
                if( k % arr[a] == 0 )
                {
                    found = true;
                }
            }

            if( found == true )cnt++;
        }

        printf("%d\n",cnt);
    }
}
