#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

int main()
{
    int t;
    lli A,B;

    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld %lld",&A,&B);

        lli a = A;
        lli b = B;

        while( A%3 == 0 || A%3 == 2 )A++;
        while( B%3 == 0 || B%3 == 2 )B--;

        lli x = A-1;
        lli y = B-1;

        if( x == y )printf("Case %d: %lld\n",kase,b-a);
        else        printf("Case %d: %lld\n",kase,(b-a+1)-((y-x)/3 + 1));
    }
}
//http://prantasarker.blogspot.com/2016/09/lightoj-1136-division-by-3.html
