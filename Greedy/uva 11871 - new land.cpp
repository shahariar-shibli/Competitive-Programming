#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define MX 2005
int n,m;
int input[MX][MX];
int H[MX];

int Histogram()
{
    stack<int>stk;

    int pos = 0;
    int Ans = 0, top , Area_with_top;

    while( pos < m )
    {
        if( stk.empty() || H[stk.top()] <= H[pos] )stk.push(pos++);
        else
        {
            top = stk.top();
            stk.pop();

            Area_with_top = H[top] * ( stk.empty()?pos : pos - stk.top() - 1);
            Ans = max(Ans,Area_with_top);
        }
    }

    while(!stk.empty())
    {
        top = stk.top();
        stk.pop();

        Area_with_top = H[top] * ( stk.empty()?pos : pos - stk.top() - 1);
        Ans = max(Ans,Area_with_top);
    }
    return Ans;
}

int Max_rectangle_area()
{
    memset(H,0,sizeof(H));
    int area = 0;
    int max_area = 0;
    for(int i = 0; i < n; i++ )
    {
        for(int j = 0; j < m; j++ )
        {
            if(input[i][j] == '1' )H[j] = 0;
            else                   H[j] += 1;
        }

        area = Histogram();
        ///cout<<area<<endl;
        max_area = max(area, max_area);
    }
    return max_area;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {

        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < m; j++ )
            {
                scanf("%d",&input[i][j]);
            }
        }
        printf("Case %d: %d\n",kase,Max_rectangle_area());

    }
}


