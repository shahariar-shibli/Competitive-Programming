//Activity Selection Problem
#include<bits/stdc++.h>
using namespace std;

#define MX 100005
int n;

struct work
{
    int Start;
    int End;

}arr[MX];

bool cmp(work a, work b)
{
    return a.End < b.End;
}

vector<int>V;   /// vector nilam

void Greedy_Activity_Selection()
{
    int k;
    V.push_back(1);      /// first kaj ta all time nite parbo
    k = 1;
    for(int i = 2; i <= n; i++ )  /// ekta kaj niye nisi tai porer kaj theke check korbo tai loop 2 theke cholbe
    {
        if( arr[i].Start >= arr[k].End )   /// jodi porer kajer starting time ager kajer enginf time theke boro ba soman hoy
        {
            V.push_back(i); /// vector e rekhe dilam
            k = i;  /// ager kaj koto number kaj chilo save rakhlam
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d",&arr[i].Start,&arr[i].End);
        }
        sort(arr,arr+n+1,cmp);

        Greedy_Activity_Selection();

        printf("%d\n",V.size());

        V.clear();
    }
}
