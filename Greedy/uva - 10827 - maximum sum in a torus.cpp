///MAXIMUM SUM 2D

#include<bits/stdc++.h>
using namespace std;

#define MX 105
int arr[MX][MX],sum[MX];

int main()
{
    int t;
    scanf("%d",&t);

    for(int ii = 1; ii <= t; ii++ )
    {
        int n;
        scanf("%d",&n);

        int cur_sum,cur_max,fin_max;
        fin_max = INT_MIN;

        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < n; j++ )
            {
                scanf("%d",&arr[i][j]);
            }
        }


        for(int i = 0; i < n; i++ )
        {
            cout<<"i choltese : "<<i<<endl<<endl;
            memset(sum,0,sizeof(sum));

            for(int j = i; j < n; j++ )
            {
                cout<<"column er jonno j choltese : "<<j<<endl<<endl;

                cur_sum = 0;
                cur_max = INT_MIN;
                int k;
                for( k = 0; k < n; k++ )
                {
                    cout<<"k choltese : "<<k<<endl;
                    sum[k] += arr[k][j];
                    cout<<"row = "<<k<<" sum = "<<sum[k]<<" column = "<<j<<endl;

                    cur_sum = max(0,cur_sum + sum[k]);
                    cout<<"current sum = "<<cur_sum<<endl;

                    cur_max = max(cur_sum,cur_max);
                    cout<<"current maximum = "<<cur_max<<endl;
                }

                fin_max = max(fin_max,cur_max);
                cout<<"row wise final max = "<<fin_max<<" row ache = "<<i<<endl;
            }
        }
        cout<<"FINAL MAXIMUM SUM = "<<fin_max<<endl;
        ///printf("%d\n",fin_max);

    }

}

