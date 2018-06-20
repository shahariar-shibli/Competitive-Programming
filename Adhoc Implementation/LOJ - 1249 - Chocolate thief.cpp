#include<bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int vol;

}arr[200];

bool cmp(student a, student b)
{
    return a.vol < b.vol;
}

int main()
{
    int t,n,x,y,z;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);

        for(int i = 0; i < n; i++ )
        {
            cin>>arr[i].name;
            scanf("%d %d %d",&x,&y,&z);
            arr[i].vol = x*y*z;
        }

        sort(arr,arr+n, cmp);
        int mn,mx,pos1,pos2;
        mn = INT_MAX;
        mx = INT_MIN;
        pos1 = pos2 = 0;
        for(int i = 0; i < n; i++ )
        {
            if( arr[i].vol < mn )
            {
                mn = arr[i].vol;
                pos1 = i;
            }
            if( arr[i].vol > mx )
            {
                mx = arr[i].vol;
                pos2 = i;
            }
        }
        printf("Case %d: ",kase);
        if( mx == mn )printf("no thief\n");
        else          cout<<arr[pos2].name<<" took chocolate from "<<arr[pos1].name<<"\n";
       // cout<<mx<<" "<<mn<<endl;
    }

}
