#include<bits/stdc++.h>
using namespace std;

#define MX 1005

map<char,int>mp;

struct freq
{
    int a;
    int b;

}arr[MX];

int t;

void init()
{
    mp.clear();
}

bool cmp( freq a, freq b )
{
    if( a.b < b.b )return true;
    if( a.b == b.b && a.a>b.a )return true;
    return false;
}

int main()
{
    int m,n,cnt;
    int kk = 1;
    string s;
    while(getline(cin,s))
    {
        init();
        n = s.size();
        for(int i = 0; i < n; i++ )
        {
            mp[s[i]] = mp[s[i]]+1;
        }

        map<char,int>::iterator it;
        m = 0;
        for(it = mp.begin(); it != mp.end(); it++ )
        {
            int a = it->first;
            int b = it->second;

            arr[m].a = a;
            arr[m].b = b;

            m++;
        }

        sort(arr,arr+m,cmp);

        if( kk != 1 )printf("\n");

        for(int i = 0; i < m; i++ )
        {
                printf("%d %d\n",arr[i].a,arr[i].b);
        }

        kk++;
    }
}
