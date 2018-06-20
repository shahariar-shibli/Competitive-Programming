#include<bits/stdc++.h>
using namespace std;

#define MX 30
bool R[MX];

int main()
{
    int n,m,x,y;

    while(scanf("%d %d",&n,&m) == 2)
    {
        if( n == 0 && m == 0 )break;
        memset(R,false,sizeof(R));

        while(m--)
        {
            scanf("%d %d",&x,&y);
            if( y < 0 )
            {
                y = y*-1;
                R[y] = true;
            }
        }

        int cnt = 0;
        for(int i = 0; i < MX; i++ )if( R[i] == true )cnt++;

        printf("%d\n",n-cnt);
    }
}
