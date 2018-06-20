#include<bits/stdc++.h>
using namespace std;

int m,n;
string X,Y;

void create_pos(int len)
{
    for(int i = 0; i < len; i++ )
    {
        if( i % 2 == 0 )Y += "+";
        else            Y += "-";
    }
}


void create_neg(int len)
{
    for(int i = 0; i < len; i++ )
    {
        if( i % 2 == 0 )Y += "-";
        else            Y += "+";
    }
}

int check()
{
    m = X.size();
    n = Y.size();

    int cnt = 0;
    for(int i = 0; i < m; i++ )
    {
        if( X[i] != Y[i] )cnt++;
    }
    return cnt;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        cin>>X;
        int len = X.size();

        create_pos(len);
        int m1 = check();
        Y= "";

        create_neg(len);
        int m2 =  check();
        Y = "";

        //cout<<m1<<" "<<m2<<endl;
        printf("%d\n",min(m1,m2));
    }
}
/*
Wagner–Fischer algorithm:
Suppose of the of string s is m, and the size of string w is n, then we create a two dimensional array d[0..m][0..n], where d[i][j] denotes the edit distance between the i-length prefix of s and j-length prefix of w.

The computation of array d is done using dynamic programming, which uses the following recurrence:
d[i][0] = i * a, for i <= m
d[0][j] = j * a, for j <= n

d[i][j] = d[i - 1][j - 1], if s[i] == w[j],
d[i][j] = min(d[i - 1][j] + a, d[i][j - 1] + a, d[i - 1][j - 1] + b), otherwise.
*/
