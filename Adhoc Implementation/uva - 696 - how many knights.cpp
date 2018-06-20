#include<bits/stdc++.h>
using namespace std;

void print(int sum,int m,int n)
{
    printf("%d knights may be placed on a %d row %d column board.\n",sum,m,n);
}

int main()
{
    int m,n;

    while(scanf("%d %d",&m,&n) != EOF )
    {
        if( m == 0 && n == 0 )break;

        if( m == 1 || n == 1 )
        {
            print((m*n),m,n);
        }

        else if( m == 2 || n == 2 )
        {
           int k,c,d;
            k = c = d = 0;

            if( m == 2 )k = n;
            else k = m;

            if( k % 4 == 0 )c = k/4;
            else c = (k/4) + 1;

            if( (k-1)%4 == 0 )d = (k-1)/4;
            else d = ((k-1)/4)+1;

            print(2*(c+d),m,n);

        }

        else
        {
            if( (m*n)%2 )
            {
                print((m*n)/2+1,m,n);
            }
            else
            {
                print((m*n)/2,m,n);
            }
        }
    }
}
