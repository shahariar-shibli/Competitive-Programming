#include<bits/stdc++.h>
using namespace std;

int A[15],B[15];

int main()
{
    int t,n,m,p,sum;

    scanf("%d",&t);

    for(int i = 1; i <= t; i++ )
    {
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));

        scanf("%d %d",&n,&m);

        for(int j = 0; j < n; j++ )
        {
            scanf("%d",&A[j]);
        }
        for(int j = 0; j < n; j++ )
        {
            scanf("%d",&B[j]);
        }

        sum = 0;
        p = 0;

        for(int j = 0; j < n; j++ )
        {
            if( B[j] < A[j] )p = 1;
            if( A[j] <= B[j] )
            {
                sum += A[j];
            }
        }

        if( sum <= m && p == 0 )printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);
    }
}
