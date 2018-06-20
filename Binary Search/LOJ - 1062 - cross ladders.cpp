#include<bits/stdc++.h>
using namespace std;

#define eps 1e-8
double a,b,c;

double MIN(double a,double b)
{
    if( a+eps < b )return a;
    else return b;
}

double func(double x)
{
    double A = sqrt(a*a - x*x);
    double B = sqrt(b*b - x*x);

    return ((A*B)/(A+B));
}

double bin_search()
{
    double low,mid,high;
    low  = 0;
    high = MIN(a,b);

    while( fabs(low - high) > eps )
    {
        mid = (low+high)/2.0;

        if( func(mid) <= c )high = mid;
        else low = mid;
    }

    return mid;
}

int main()
{
    int t;
    scanf("%d",&t);
    //double val = 0.0;
    for(int i = 1; i <= t; i++ )
    {
        scanf("%lf %lf %lf",&a,&b,&c);

        printf("Case %d: %0.15lf\n",i,bin_search());
    }
}
