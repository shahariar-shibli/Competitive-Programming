#include<bits/stdc++.h>
using namespace std;

int m,n;
string X,Y,Z;

void convert_string(int len)
{
    for(int i = 0; i < len; i++ )
    {
        if( X[i] >= 'A' && X[i] <= 'Z')Z += "+";
        else                           Z += "-";
    }
}

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
        if( Z[i] != Y[i] )cnt++;
    }
    return cnt;
}

int main()
{
    while(cin>>X)
    {
        int len = X.size();

        convert_string(len);

        create_pos(len);
        int m1 = check();
        Y = "";

        create_neg(len);
        int m2 =  check();
        Y = Z = "";

        //cout<<m1<<" "<<m2<<endl;
        printf("%d\n",min(m1,m2));
    }
}
