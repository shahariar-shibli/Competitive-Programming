#include<bits/stdc++.h>
using namespace std;

#define MX 1000100
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

int KMP_match_index()
{
    KMP_failure();
    Match_Position.clear();

    int n = strlen(text);
    int m = strlen(pattern);
    int j = 0;
    int mx = 0;

    for(int i = 0; i < n; i++ )
    {
        while( j > 0 && text[i] != pattern[j] )j = pi[j];
        if( text[i] == pattern[j] )j = j + 1;
        if( j == m )return -1;
        mx = max(mx,j);
    }
    return mx;
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for( int kase = 1; kase <= t; kase++ )
    {
        gets(pattern);
        int len = strlen(pattern);

        for(int i = 0; i < len; i++ )text[i] = pattern[len-i-1];   // reverse of text

        int indx = KMP_match_index(); // find the index for how many characters in pattern matches with text; remained characters to add

        if( indx >= 0 )
        {
            for(int i = indx-1; i >= 0; i-- )printf("%c",pattern[i]);
            printf("\n");
        }
        else puts(pattern);

        memset(text,0,sizeof(text));
    }
}

