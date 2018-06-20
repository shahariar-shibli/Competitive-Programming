//MAXIMUM SUM 1D

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while( scanf("%d",&n) == 1 )
    {
        if( n == 0 )break;

        int x,curr_sum,max_sum;

        curr_sum = 0;
        max_sum = INT_MIN;

        for(int i = 0; i < n; i++ )
        {
            scanf("%d",&x);
            curr_sum += x;

            //cout<<"current sum is : "<<curr_sum<<endl;

            if( curr_sum > max_sum )max_sum = curr_sum;

            //cout<<"maximum sum is : "<<max_sum<<endl;

            if( curr_sum < 0 )curr_sum = 0;

        }
        //cout<<"Final maximum sum is : "<<max_sum<<endl;

        if( max_sum > 0 )printf("The maximum winning streak is %d.\n",max_sum);
        else printf("Losing streak.\n");
    }
}
