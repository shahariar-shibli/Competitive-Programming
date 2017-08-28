//Matrix Chain Multiplication.
#include<bits/stdc++.h>
using namespace std;

#define MX 100
#define inf 1e8
int M[MX][MX],S[MX][MX],P[MX];
int x,cnt;

void init(int n)
{
    memset(P,0,sizeof(P));

    for(int i = 0; i <= n; i++ )
    {
        for(int j = 0; j <= n; j++ )
        {
            M[i][j] = 0;
        }
    }
}


void Matrix_Chain_Order()
{
    int n = x-1;

    for(int i = 1; i <= n; i++ )M[i][i] = 0;

    for(int l = 2; l <= n; l++ )
    {
        for(int i = 1; i <= n-l+1; i++ )
        {
            int j = i + l -1;

            M[i][j] = inf;

            for(int k = i; k <= j -1; k++ )
            {
                int q = M[i][k] + M[k+1][j] + (P[i-1] *P[k] *P[j]);

                if( q < M[i][j] )
                {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

void Print_Optimal_Parens(int i,int j)
{
    if( i == j )printf("A%d",i);
    else
    {
        printf("(");
        Print_Optimal_Parens(i,S[i][j]);
        printf(" x ");
        Print_Optimal_Parens(S[i][j]+1, j);
        printf(")");
    }
}
int main()
{
    int q1,q2,sum,tum,t;
    sum = tum = t = 0;
    while( scanf("%d",&x) == 1 )
    {
        if( x == 0 )break;

        t++;
        tum = x;
        x++;
        init(x);

        cnt = 0;

        for(int i = 0; i < tum; i++ )
        {
            cnt++;
            scanf("%d %d",&q1,&q2);
            sum = q2;
            P[i] = q1;
        }

        P[cnt] = sum;

        Matrix_Chain_Order();

        printf("Case %d: ",t);
        Print_Optimal_Parens(1,x-1);
        printf("\n");

    }
}
/*
7
30 35 15 5 10 20 25
*/

