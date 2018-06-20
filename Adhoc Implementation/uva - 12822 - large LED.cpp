#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 100005
int T[MX];
int L[] = {6,2,5,5,4,5,6,3,7,6};

struct score
{
    int home;
    int guest;

}S[MX];

int cal_time(int h,int m,int s)
{
    return h*60*60 + m*60 + s;
}

int cal_seg(int seg)
{
    if( seg == 0 )return L[seg];
    else
    {
        int x = seg;
        int tmp = 0;
        while(x != 0)
        {
            int y = x%10;
            x = x /10;
            tmp += L[y];
        }
        return tmp;

    }


}

int main()
{
    string s;
    int h,m,ss;

    int p,hom,gues,q;
    p = hom = gues = q = 0;

    int kase = 1;
    while(cin>>s)
    {
        if( s == "START" )
        {
            scanf("%d:%d:%d",&h,&m,&ss);
            T[p++] = cal_time(h,m,ss);

            S[q].home = hom;
            S[q].guest = gues;
            q++;
        }
        else if( s == "END")
        {
            scanf("%d:%d:%d",&h,&m,&ss);
            T[p++] = cal_time(h,m,ss);

            lli sum = 0,total = 0;
            int tt = 0;

            for(int i = 0; i < q; i++ )
            {
                sum = cal_seg(S[i].home) + cal_seg(S[i].guest);
                tt  = T[i+1] - T[i];
                total += sum*tt;

            }
            printf("Case %d: %lld\n",kase++,total);

            p = q = hom = gues = 0;
        }
        else
        {
            scanf("%d:%d:%d",&h,&m,&ss);
            T[p++] = cal_time(h,m,ss);

            string x;
            int top;

            cin>>x>>top;
            if( x == "home" )hom += top;
            else             gues += top;

            S[q].home = hom;
            S[q].guest = gues;
            q++;

        }

    }
}

