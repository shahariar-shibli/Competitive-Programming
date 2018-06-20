#include<bits/stdc++.h>
using namespace std;

#define MX 33
int arr[MX];

int main()
{
    int t;
    cin>>t;

    for(int kase = 1; kase <= t; kase++ )
    {
        for(int i = 0; i < 30; i++ )cin>>arr[i];

        int sum = 0;
        bool ok = false;
        for(int i = 0; i < 30; i++ )
        {
            if( arr[i] == 1 )sum++;
            else sum = 0;

            if( sum > 5 )
            {
                ok = true;
                break;
            }
        }
        if( ok )printf("#coderlifematters\n");
        else printf("#allcodersarefun\n");

    }
}
