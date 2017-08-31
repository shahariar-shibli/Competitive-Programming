// less than 2^31 all divisor generate
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli L,P;

///bitwise sieve start
#define chekb(x) (flag[x>>6] & (1 << ((x >> 1) & 31)))
#define setb(x)  (flag[x>>6] = (flag[x>>6] |  (1 << ((x >> 1) & 31))))
#define isp(x)   ((x==2) || (x>1 && (x&1) && !chekb(x))) //checks is_prime
const int mx = 47000;
const int S  = sqrt(mx)+1;
int flag[(mx>>6)+10];
int prime[4860];
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
int nk , e[4850+10];
lli p[4850+10];
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

/// All Divisor Generate : this took time = 0.004 sec
lli divisors[10000];
int dnt;
void countdiv()
{
    int i , j, k , n;
    divisors[0] = 1;
    dnt = 1;
    for (int i = 0; i < nk; i++)
    {
        int n = dnt;
        for (int j = 0; j < e[i]; j++)
        {
            for (int a = 0; a < n; a++)
            {
               divisors[dnt++] = p[i] * divisors[a + j * n];
            }
        }
    }
    ///return dnt;
}

int main()
{
    siv();
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld %lld",&P,&L);

        if(L >= P-L)printf("Case %d: impossible\n",kase);
        else
        {
            decomp(P - L);
            countdiv();

            sort(divisors,divisors+dnt);

            printf("Case %d:",kase);
            for(int i = 0; i < dnt; i++ )
            {
                if( divisors[i] > L )printf(" %lld",divisors[i]);

            }
            printf("\n");
        }
    }
}


/* All Divisor Generate Recursive : this took time 0.004 also
lli Divisor[10000], dnt;
void DivisorGenerate(int idx, int num)
{
    if( idx == nk ) {
        if( num > L ) Divisor[dnt++] = num;
        return ;
    }
    int val = 1;
    for(int i = 0; i <= e[idx]; i++){
        DivisorGenerate(idx+1, num*val);
        val=val*p[idx];
    }
}

int main()
{
    siv();
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld %lld",&P,&L);

        if(L >= P-L)printf("Case %d: impossible\n",kase);
        else
        {
            decomp(P - L);

            dnt = 0;
            DivisorGenerate(0,1);

            sort(Divisor,Divisor+dnt);

            printf("Case %d:",kase);
            for(int i = 0; i < dnt; i++ )
            {
                printf(" %lld",Divisor[i]);
            }
            printf("\n");
        }
    }
}
*/

/* another method : this took time = 0.072 sec

typedef long long lli;
lli P,L;

/// prime factorization start

vector<lli>V;
void decomp(lli a)
{
    int i ,j ,k;
    lli n = a;

    for( i = 1; i <= sqrt(n); i++)
    {
       if( !(n % i) )
       {
           if( n/i > L )V.push_back(n/i);              // optimization
           if( i > L && n/i != i )V.push_back(i);      // optimization
       }
    }
}
/// prime factorization end

int main()
{
    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++ )
    {
        scanf("%lld %lld",&P,&L);
        V.clear();

        decomp(P - L);
        sort(V.begin(),V.end());

        if( V.size() == 0 || L >= P-L)printf("Case %d: impossible\n",kase);
        else
        {
            printf("Case %d:",kase);
            for(int i = 0; i < V.size(); i++ )printf(" %lld",V[i]);
            printf("\n");
        }
    }
}
*/
