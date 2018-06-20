#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long r1,c1,r2,c2;

    scanf("%d",&t);

    for(int i = 1; i <= t; i++ )
    {
        scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);

        long long check1 = (r1 + c1)%2;
        long long check2 = (r2 + c2)%2;
        long long check3 = llabs(r2 - r1);
        long long check4 = llabs(c2 - c1);

        if      ( check1 != check2 )printf("Case %d: impossible\n",i);
        else if ( check3 == check4 )printf("Case %d: 1\n",i);
        else                        printf("Case %d: 2\n",i);
    }

}

//Once you believe that you have mastered something,from that moment you are no longer the master.


