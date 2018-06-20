#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

void make_string()
{
    c = d = "";
    for(int i = 0; i < a.size(); i++ )
    {
        if( a[i] != b[i] )c += "1";
        else              c += "0";

        if( a[i] == '1' && b[i] == '1' )d += "1";
        else                            d += "0";
    }
}

void left_shift()
{
    for(int i = 1; i < d.size(); i++ )
    {
        d[i-1] = d[i];
    }
    d[d.size()-1] = '0';
}

bool check()
{
    make_string();

    if( d[0] == '1' )
    {
        d = "overflow";
        return false;
    }

    left_shift();

    for(int i = 0; i < d.size(); i++ )
    {
        if( d[i] == '1' )return true;
    }
    return false;
}


int main()
{
    int t;
    scanf("%d",&t);
    getchar();

    for(int kase = 1; kase <= t; kase++ )
    {
        if( kase > 1 )printf("\n");

        cin>>a>>b;
        cout<<a<< " "<< b<<endl;
        while(1)
        {
            if( !check() )break;
            a = c;
            b = d;
            cout<<a<<" "<<b<<endl;
            //c = d = "";
        }

        cout<<c<< " " <<d<<endl;
        //a = b = c = d = "";
    }
}
