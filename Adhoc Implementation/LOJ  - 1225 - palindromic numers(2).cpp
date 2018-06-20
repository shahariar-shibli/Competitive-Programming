#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[1000];
    for(int i = 1; i <= t; i++ )
    {
        scanf("%s",s);

        int n = strlen(s);
        bool flag = false;

        for(int j = 0; j < n/2; j++ )
        {
            if( s[j] != s[n-1-j] )flag = true;
        }

        if( flag )printf("Case %d: No\n",i);
        else printf("Case %d: Yes\n",i);
    }
}
