// solve v - vx/100 < m-1 equation.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,ans;
    int x;
    ans = 0;
    while(scanf("%lld %d",&m,&x) == 2 )
    {
        ans = 0;
        if( m == 0 && x == 0 )break;

        if( x == 100 )
        {
            printf("Not found\n");
            //break;
        }
        else
        {
            ans = 100*(m-1) /(100-x);


            //cout<<ans<<endl;

            if( 100*(m-1) % ( 100 - x ) == 0  )
            {
                ans = ans - 1;
            }
            if ( ans < m )
            {
                printf("Not found\n");
            }
            else printf("%lld\n",ans);
        }
    }
}
