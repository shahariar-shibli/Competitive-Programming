#include<bits/stdc++.h>
using namespace std;


list<char>LIST;

int main()
{
    string s;
    while(cin>>s)
    {
        list<char>::iterator it = LIST.begin();
        for(int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '[')it = LIST.begin();
            if( s[i] == ']')it = LIST.end();
            if( s[i] != '[' && s[i] != ']') LIST.insert(it,s[i]);
        }

        for(it= LIST.begin(); it != LIST.end(); it++ )
        {
            cout<<*it;
        }
        cout<<endl;

        while(!LIST.empty())
        {
            LIST.pop_back();
        }
    }
}
