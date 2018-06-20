#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,fast,last,cnt;

    while(scanf("%d %d",&x,&y) == 2)
    {
        fast = last = cnt = 0;
        while(abs(fast-last) < x)
        {
            fast += x;
            last += y;
            cnt++;
        }

        printf("%d\n",cnt+1);
    }
}
