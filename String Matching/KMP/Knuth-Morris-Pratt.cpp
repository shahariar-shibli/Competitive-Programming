#include<bits/stdc++.h>
using namespace std;

#define MX 1000007
int pi[MX];
vector<int>Match_Position;

void KMP_failure(string pattern)
{
    memset(pi,0,sizeof(pi));

    int m = pattern.size();
    pi[1] = 0;
    int j = 0;

    for(int i = 2; i <= m; i++ )
    {
        while( j > 0 && pattern[i-1] != pattern[j] )j = pi[j];
        if( pattern[i-1] == pattern[j] )j = j + 1;
        pi[i] = j;
    }
}

bool KMP_match_finder(string text, string pattern)
{
    KMP_failure(pattern);

    int n = text.size();
    int m = pattern.size();
    int j = 0;

    for(int i = 0; i < n; i++ )
    {
        while( j > 0 && text[i] != pattern[j] )j = pi[j];
        if( text[i] == pattern[j] )j = j + 1;
        if( j == m )return true;
    }
    return false;
}

void KMP_match_index(string text, string pattern)
{
    KMP_failure(pattern);
    Match_Position.clear();

    int n = text.size();
    int m = pattern.size();
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
    string A,B;
    while(getline(cin,A))
    {
        getline(cin,B);

        if( KMP_match_finder(A,B) )printf("Found\n");
        else    printf("Not Found\n");

        KMP_match_index(A,B);
        printf("Pattern Occurs: ");
        printf("%d times\n",Match_Position.size());

        printf("Pattern Occurs at index: ");
        int len = Match_Position.size();
        for(int i = 0; i < len; i++ )
        {
            if( i > 0 && i < len )printf(" ");
            printf("%d",Match_Position[i]);
        }
        printf("\n");
    }
}
