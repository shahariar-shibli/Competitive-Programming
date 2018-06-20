//uva 12439
#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

string arr[12]={"January","February","March","April","May","June",
                "July","August","September","October",
                "November","December"};

int check_month(string s)
{
   for(int i = 0; i < 12; i++ )
   {
       if( arr[i] == s )return i+1;
   }
}

bool check_leap(lli y)
{
    if( ( y % 4 == 0 && y % 100 != 0 ) || ( y % 400 == 0 ) )return true;
    else                                                    return false;
}

int main()
{
    int t;
    scanf("%d",&t);

    string a,b;
    int d1,d2;
    lli y1,y2;
    char ch;
    for(int kase = 1; kase <= t; kase++ )
    {
        cin>>a>>d1>>ch>>y1;
        cin>>b>>d2>>ch>>y2;

        int m1 = check_month(a);
        //cout<< "starting month = "<<m1<<endl;
        if( m1 > 2 )y1++;

        int m2 = check_month(b);
        //cout<< "ending month = "<<m2<<endl;
        if( m2 < 2 || ( m2 == 2 && d2 < 29 ))y2--;

        lli f = ( y2 / 4 ) - ( y1 - 1 )/4;
        lli h = ( y2 / 100 ) - ( y1 - 1 )/100;
        lli fh= ( y2 / 400 ) - ( y1 - 1 )/400;

        //cout<<"f = "<<f<<" "<<"h = "<<h<<" "<<"fh = "<<fh<<endl;

        printf("Case %d: %lld\n",kase,(f-h+fh));
    }
}
//http://ojsolver.blogspot.com/2015/10/uva-12439-february-29-solution-methods.html
