#include<bits/stdc++.h>
using namespace std;

int s[1000],p;

void init()
{
    memset(s,0,sizeof(s));
}

int check(int n)
{
    int cnt = 0;
    while( n > 0 )
    {
        //cout<<22<<endl;
        if( (n % 2) != 0 )
        {
            cnt++;
            n = n/2;
        }
        else
        {
            n = n /2;
        }
    }
    return cnt;
}

void decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    p = 0;
    while (n!=0)
    {
        s[p++]=n%2;
        n/=2;
        //s[p++]=(rem*i);
        i*=10;
    }
    //return binary;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1 )
    {
        init();
        if( n == 0 )break;
        decimal_binary(n);
        cout<<"The parity of ";

        for(int j = p-1; j >=0 ; j-- )
        {
            printf("%d",s[j]);
        }
        cout<<" is "<<check(n)<<" (mod 2).\n";

        //printf("The parity of %s is %d (mod 2).\n",s,check(n));
    }

}
