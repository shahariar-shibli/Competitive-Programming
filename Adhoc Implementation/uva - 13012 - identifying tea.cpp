#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cnt;
    int arr[6];

    while(scanf("%d",&t) != EOF )
    {
        cnt = 0;
        for(int i = 0 ; i < 5; i++ )
        {
            scanf("%d",&arr[i]);
            if( arr[i] == t )cnt++;
        }

        printf("%d\n",cnt);

    }

}
