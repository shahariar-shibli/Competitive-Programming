#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

lli arr[21] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000 ,85766121};

int main()
{
    lli x;
    while(scanf("%lld",&x) == 1)
    {
        if( x == 0 )break;

        bool ok = false;
        for(int i = 0 ; i < 21; i++ )
        {
            if( arr[i] == x )
            {
                ok = true;
                break;
            }
        }

        if( ok )printf("Special\n");
        else    printf("Ordinary\n");
    }

}
