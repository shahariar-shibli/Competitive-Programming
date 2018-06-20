//minimum Euclidean distance from a point to a line segment.(ternary search)
#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-8
#define INF 1e12
double ax,ay,az,bx,by,bz,cx,cy,cz;
double line0x,line0y,line0z;

double get_distance(double x0,double y0,double z0,double x1,double y1,double z1)
{
    double dist = (x1 - x0)*(x1 - x0) + (y1- y0)*(y1 - y0) + (z1 - z0)*(z1 - z0);
    return sqrt(dist);
}

double EQU(double scalar)
{
    double point0x,point0y,point0z;

    point0x = ax + line0x * scalar;
    point0y = ay + line0y * scalar;
    point0z = az + line0z * scalar;

    return get_distance(point0x,point0y,point0z,cx,cy,cz);

}

double ternary_search()
{
    double low,high,ans;
    low = 0; high = 1; ans = INF;
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
    scanf("%d",&t);
    for(int i = 1; i <= t; i++ )
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&az,&bx,&by,&bz,&cx,&cy,&cz);
        line0x = bx - ax;
        line0y = by - ay;
        line0z = bz - az;
        printf("Case %d: %.15lf\n",i,ternary_search());
    }
}
