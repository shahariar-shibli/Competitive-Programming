#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    double L,D,H,V;
    double T,s;

    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lf %lf %lf %lf",&L,&D,&H,&V);

        T = 2*H;
        T = T/(1000.0*9.81);
        T = sqrt(T);

        s = V*T*1.00;

        if( s >= D + 500 && s <= D+L-500 )printf("POOL\n");
        else if( fabs(s - D) < 500 || fabs(s - D - L) < 500 )printf("EDGE\n");
        else printf("FLOOR\n");
    }
}
