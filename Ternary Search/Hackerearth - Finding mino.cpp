/*You have been given an Unimodal function:
f(x)=2x^2 - 12x + 7 , you need to find the minimum value of f(x)
where x will be in the range [l,r](both inclusive).*/

#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-8
#define INF 1e12

double EQU(double scalar)
{
   return 2*scalar*scalar - 12 * scalar + 7;
}

double ternary_search(double l, double r)
{
    double low,high,ans;
    low = l; high = r; ans = INF;

    while( low + EPS <= high )
    {
         double left_third  = low + ( high - low )/3;
         double right_third = high - ( high - low )/3;
         double leftvalue = EQU(left_third);
         double rightvalue = EQU(right_third);

        if( leftvalue <= rightvalue )
        {
            high = right_third;
            ans = min(ans,leftvalue);
        }
        else if( rightvalue < leftvalue )
        {
            low = left_third;
            ans = min(ans,rightvalue);
        }
    }
    return ans;
}

int main()
{
    int t;
    double a,b;
    scanf("%d",&t);

    for(int i = 1; i <= t; i++ )
    {
        scanf("%lf %lf",&a,&b);
        printf("%0.0lf\n",ternary_search(a,b));
    }
}
