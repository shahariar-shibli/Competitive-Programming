/*
long long H(int n){
    long long res = 0;
    for( int i = 1; i <= n; i=i+1 )
    {
        res = (res + n/i);
    }
    return res;
}

minimize time limit.
*/


#include<bits/stdc++.h>
using namespace std;

long long func(long long n)
{
    long long sum = 0;
    int root = (int)sqrt(n);
    root++;
    //cout<<root<<endl;
    long long res = 0;
    for(int i = 1; i < root; i++ )
    {
        res = res + ( n/i);
    }

    //res = res * n;
    sum = 2*res;
    //cout<<sum<<endl;
    root--;
    sum = sum -(root*root);

    return sum;

}


int main()
{
    long long n;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",func(n));
    }
}
