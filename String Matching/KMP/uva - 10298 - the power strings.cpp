#include<bits/stdc++.h>
using namespace std;

#define MX 1000007
char pattern[MX];
int pi[MX];

void KMP_failure()
{
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

int main ()
{
    while(1)
    {
        scanf("%s", pattern);
        if( pattern[0] == '.' )break;

//        cout<<pattern<<endl;
        KMP_failure();

//        for(int i = 1; i <= strlen(pattern); i++ )
//        {
//            cout<<pi[i]<<" ";
//        }
//        cout<<endl;

        int len = strlen(pattern);
        printf("%d\n", len/ (len - pi[len]));
    }
}
