#include<bits/stdc++.h>
using namespace std;

#define MX 5005
int arr[MX];
bool check[26];

void pre_cal()
{
    for( int i = 1 ; i <= MX ; i++ )
    {
            memset(check,false,sizeof(check));

            int x = i;

            while( x )
            {
                if( check[x % 10] == 1 )break;
                check[x % 10] = true;
                x = x/10;
            }

            if( x == 0 )arr[i] = 1;
            arr[i] += arr[i-1];
    }
}

int main()
{
    int n,m;

    pre_cal();

    while( scanf("%d %d",&n,&m) == 2 )
    {
        printf("%d\n",arr[m] - arr[n-1] );
    }
}
 // To iterate is human, to recurse divine.  - L. Peter Deutsch
