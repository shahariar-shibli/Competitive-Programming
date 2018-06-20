#include<bits/stdc++.h>
using namespace std;

#define MX 4
map<char,int>mp;
int arr[MX];

int main()
{
    int t;
    string s;

    mp['C'] = 0;
    mp['H'] = 1;
    mp['O'] = 2;
    mp['N'] = 3;

    scanf("%d",&t);
    getchar();

    for(int kase = 1; kase <= t; kase++ )
    {
        memset(arr,0,sizeof(arr));
        cin>>s;

        for(int i = 0; i < s.size(); i++ )
        {
            if( !(s[i] >= '0' && s[i] <= '9') )arr[mp[s[i]]]++;
            else
            {
                int cnt,idx;
                cnt = idx = 0;

                for(int j = i; j < s.size(); j++ )
                {
                    if( !(s[j] >= '0' && s[j] <= '9') )break;
                    cnt = (cnt*10) + s[j] - '0';
                    idx = j;
                }
                arr[mp[s[i-1]]] += cnt-1;
                i = idx;
            }
        }

        double sum  = 0.0;

        //cout<<arr[0] <<" "<<arr[1]<< " "<<arr[2]<< " "<<arr[3]<<endl;

        sum  = arr[0] * 12.01;
        sum += arr[1] * 1.008;
        sum += arr[2] * 16.00;
        sum += arr[3] * 14.01;

        printf("%0.3lf\n",sum);

    }

}
