#include<bits/stdc++.h>
using namespace std;

map<int,string>mp;
char s[100][100];
vector<string>V;
int main()
{
    string s;
    mp[0] = "Happy";
    mp[1] = "birthday";
    mp[2] = "to";
    mp[3] = "you";
    mp[4] = "Happy";
    mp[5] = "birthday";
    mp[6] = "to";
    mp[7] = "you";
    mp[8] = "Happy";
    mp[9] = "birthday";
    mp[10] = "to";
    mp[11] = "Rujia";
    mp[12] = "Happy";
    mp[13] = "birthday";
    mp[14] = "to";
    mp[15] = "you";

    int t,p;
    //p = 1;
    while(scanf("%d",&t) != EOF){

    V.clear();
    p = 1;
    for(int i = 0; i < t; i++ )
    {
       //scanf("%s",s[i]);
       cin>>s;
       V.push_back(s);

    }


    if( t > 16)p = (int)ceil(t/16)+1;

    int i,j,k;

    for( i = 0, j = 0, k = 0; i < 16*p; i++,j++,k++ )
    {
        if( j == t ) j = 0;
        if( i == 16 )k = 0;
        cout<<V[j]<<": "<<mp[k]<<endl;
    }

    }
}
