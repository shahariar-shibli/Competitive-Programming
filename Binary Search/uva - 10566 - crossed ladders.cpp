#include<bits/stdc++.h>
using namespace std;

#define eps 1e-8
double a,b,c;

double func(double x)
{
    double A = sqrt(a*a - x*x);
    double B = sqrt(b*b - x*x);

    return ((A*B)/(A+B));
}

double MIN(double a,double b)
{
    if( a + eps < b )return a;
    else return b;
}

double bin_search()
{
    double low,high,mid;

    low = 0;
    high = MIN(a,b);

    while( fabs(low-high) > eps )
    {
        mid = (low+high)/2.0;

        if(func(mid) <= c )high = mid;
        else low = mid;
    }

    return mid;

}

int main()
{
    while(scanf("%lf %lf %lf",&a,&b,&c) != EOF )
    {
        printf("%0.3lf\n",bin_search());
    }
}
