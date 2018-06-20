#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 50005

struct process
{
    lli start;
    bool ok;

}arr[MX*2];

bool cmp(process a, process b)
{
    if( a.start == b.start )return a.ok < b.ok;
    else                    return a.start < b.start;
}

int main()
{
    int t,n;
    scanf("%d",&t);

    lli S,T;

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);

        int idx = 0;
        for(int i = 0; i < n; i++ )
        {
            scanf("%lld %lld",&S,&T);

            arr[idx].start = S;
            arr[idx].ok = 0;
            idx++;
            arr[idx].start = T;
            arr[idx].ok = 1;
            idx++;
        }

        sort(arr,arr+idx,cmp);

       /* for(int i = 0; i < idx; i++ )
        {
            cout<<arr[i].start<<" = "<<arr[i].ok<<endl;
        }
        */


        int cnt = 0;
        int curr_max = 0;
        for(int i = 0; i < idx; i++ )
        {
            if( arr[i].ok == 0 )cnt++;
            else if( arr[i].ok == 1 )cnt--;

            //cout<<cnt<<endl;

            curr_max = max(curr_max,cnt);
            //cout<<curr_max<<endl;
        }
       // cout<<curr_max<<endl;
        printf("Case %d: %d\n",kase,curr_max);
    }


}
/*
3
5
1 1
2 2
3 3
4 4
5 5
4
11 23
1 5
3 6
2 9
4
0 5
5 6
2 9
9 13
*/
