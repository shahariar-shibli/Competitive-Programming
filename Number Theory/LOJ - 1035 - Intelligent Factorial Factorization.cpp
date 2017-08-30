#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

///bitwise sieve start
#define chekb(x) (flag[x>>6] & (1 << ((x >> 1) & 31)))
#define setb(x)  (flag[x>>6] = (flag[x>>6] |  (1 << ((x >> 1) & 31))))
#define isp(x)   ((x==2) || (x>1 && (x&1) && !chekb(x))) //checks is_prime
const int mx = 1000;
const int S  = sqrt(mx)+1;
int flag[(mx>>6)+10];
int prime[168+10];
int np;
void siv(void)
{
    int i,j,k;
    np=0; setb(0);
    prime[np++]=2;
    for(i=3;i<=S;i+=2)
        if(!chekb(i))
            for(prime[np++]=i ,j=i*i ,k=i<<1 ; j<=mx ; j+=k)
                setb(j);
    for(;i<=mx;i+=2) if(!chekb(i)) prime[np++]=i;
}
/// bitwise end

/// prime factorization start
int nk , e[78498+10];
lli p[78498+10];
int cnt;
lli sum;
void decomp(lli a)
{
    int i ,j ,k;
    lli n =a;
    nk=0;
    for(i=0;i < np && prime[i]*prime[i] <= n;i++)
    {
        cnt=0;
        while(!(n%prime[i]))n/=prime[i],cnt++;
        if(cnt) p[nk] = prime[i] , e[nk]=cnt , nk++;
    }
    if(n != 1) p[nk]=n , e[nk]=1, nk++;
}
/// prime factorization end

/// prime factorization for factorials start
int nk1 , e1[168+10];
lli p1[168+10];
int cnt1;
lli sum1;
void decomp1(lli a)
{
    int i ,j ,k;
    lli n = a;
    nk1=0;
    lli nn;
    for(i=0;i < np && prime[i] <= n;i++)
    {
        cnt1=0;
        nn= n;
        while(nn>0)cnt1+=nn/prime[i], nn/=prime[i];
        if(cnt1) p1[nk1] = prime[i] , e1[nk1]=cnt1 , nk1++;
    }
}
/// prime factorization for factorials end

int main()
{
    siv();

    int t;
    lli a,b,inp;

    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld",&inp);

        decomp1(inp);

        printf("Case %d: %lld = ",kase,inp);

        for(int i = 0; i < nk1; i++ )
        {
            if( i == 0 )
            {
                printf("%lld",p1[i]);
                printf(" (%d)",e1[i]);
            }
            else
            {
                if( i > 0 && i < nk1 )printf(" * ");
                printf("%lld",p1[i]);
                printf(" (%d)",e1[i]);
            }
        }
        printf("\n");

    }


}
