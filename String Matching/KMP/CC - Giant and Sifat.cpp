#include<bits/stdc++.h>
using namespace std;

#define MX 1000007
int pi[MX];
vector<int>Match_Position;

void KMP_failure(string pattern)
{
    //memset(pi,0,sizeof(pi));

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

int KMP_match_index(string text, string pattern)
{
    KMP_failure(pattern);
    int cnt = 0;

    int n = text.size();
    int m = pattern.size();
    int j = 0;

    for(int i = 0; i < n; i++ )
    {
        while( j > 0 && text[i] != pattern[j] )j = pi[j];
        if( text[i] == pattern[j] )j = j + 1;
        if( j == m )
        {
            //Match_Position.push_back(i-m+1);
            cnt++;
            j = pi[j];
        }
    }
    return cnt;
}

int main()
{
    string A,B;
    int t;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {

       getline(cin,A);
       getline(cin,A);
       cin>>B;

       //cout<<A<<endl;

       string X = "";
       for(int i = 0; i < A.length(); i++ )
       {
           if( A[i] != ' ' )X = X + A[i];
       }
       A = X;

       printf("Case %d: %d\n",kase,  KMP_match_index(A,B));
    }
}
