#include<bits/stdc++.h>
using namespace std;

#define MX 100010
char text[MX], pattern[MX];
int pi[MX];
vector<int>Match_Position;

void KMP_failure()
{
    //memset(pi,0,sizeof(pi));

    int m = strlen(pattern);
    pi[1] = 0;
    int j = 0;

    for(int i = 2; i <= m; i++ )
    {
        while( j > 0 && pattern[i-1] != pattern[j] )j = pi[j];
        if( pattern[i-1] == pattern[j] )j = j + 1;
        pi[i] = j;
    }
}

bool KMP_match_finder()
{
    KMP_failure();

    int n = strlen(text);
    int m = strlen(pattern);
    int j = 0;

    for(int i = 0; i < n; i++ )
    {
        while( j > 0 && text[i] != pattern[j] )j = pi[j];
        if( text[i] == pattern[j] )j = j + 1;
        if( j == m )return true;
    }
    return false;
}

void KMP_match_index()
{
    KMP_failure();
    Match_Position.clear();

    int n = strlen(text);
    int m = strlen(pattern);
    int j = 0;

    for(int i = 0; i < n; i++ )
    {
        while( j > 0 && text[i] != pattern[j] )j = pi[j];
        if( text[i] == pattern[j] )j = j + 1;
        if( j == m )
        {
            Match_Position.push_back(i-m+1);
            j = pi[j];
        }
    }
}

int main()
{
    int t,q;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%s", text);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s", pattern);
            if( KMP_match_finder() )printf("y\n");
            else printf("n\n");
        }
    }
}
