#include<bits/stdc++.h>
using namespace std;

vector<long long int>V;

int main()
{
    long long int n,m,ans;
    while(scanf("%lld %lld",&n,&m) == 2 )
    {

        if( m > n || n < 2 || m < 2 )
        {
            printf("Boring!\n");
            continue;
        }

        //ans = n;
        V.clear();
        //V.push_back(n);
        bool found = false;
        while( n > 1)
        {
            if( n % m == 0  )
            {
                //n = n/m;
                V.push_back(n);
            }
            else
            {
                found = true;
                //break;
            }
            n = n / m;
        }
        V.push_back(1);
        if( found == true )printf("Boring!\n");

        //printf("1\n");
        else
        {
            //printf("%lld ",ans);
            for(int j = 0; j < V.size(); j++ )
            {
                if( j >= 1)printf(" ");
                printf("%d",V[j]);
            }
            printf("\n");
        }

    }
}
