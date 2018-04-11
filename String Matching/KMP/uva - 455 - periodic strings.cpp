#include<bits/stdc++.h>
using namespace std;

#define MX 100
char pattern[MX];
int pi[MX];

void KMP_failure()
{
    //memset(pi,0,sizeof(pi));

    int m = strlen(pattern);
    pi[1] = 0;
    int j = 0;

    for(int i = 2; i <= m; i++ )
    {
        while( j > 0 && pattern[i-1] != pattern[j] )j = pi[j];
        if( pattern[i-1] == pattern[j] )j++;
        pi[i] = j;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();

    //bool spase = false;
    for(int kase = 1; kase <= t; kase++ )
    {
        getchar();
        gets(pattern);
        KMP_failure();

        int len = strlen(pattern);
        int ans = len - pi[len];

        if( len % ans == 0 )printf("%d\n",ans);
        else printf("%d\n",len);
        //cout<<len - pi[len]<<endl;

        if( kase < t )printf("\n");
    }

}

