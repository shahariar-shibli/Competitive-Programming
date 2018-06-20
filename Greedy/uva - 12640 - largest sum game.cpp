//MAXIMUM SUM 1D
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int x;
    int curr_sum,max_sum;
    while(getline(cin,s))
    {
        curr_sum = 0;
        max_sum = INT_MIN;

        //cout<<s.size()<<endl;
        stringstream ss(s);
        while(ss>>x)
        {
            curr_sum += x;
            if( curr_sum > max_sum )max_sum = curr_sum;
            if( curr_sum < 0 )curr_sum = 0;
        }

        if( max_sum < 0 )max_sum = 0;
        printf("%d\n",max_sum);
    }
}
