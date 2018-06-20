#include<bits/stdc++.h>
using namespace std;

#define MX 10005
int arr[MX];

int main()
{
    int n;
    while(scanf("%d",&n) == 1 )
    {
        if( n == -1 )break;

        int sum = 0;
        for(int i = 0; i < n; i++ )
        {
            scanf("%d",&arr[i]);
            sum = sum + arr[i];
        }

        if( sum%n )
        {
            printf("-1\n");
            continue;
        }

        int avg = sum/n;
        int cnt = 0;
        for(int i = 0; i < n; i++ )
        {
            arr[i] = arr[i] - avg;
            if( arr[i] < 0 )cnt = cnt+arr[i];
        }
        printf("%d\n",-cnt);
    }
}
