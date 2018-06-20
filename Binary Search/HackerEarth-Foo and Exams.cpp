#include<bits/stdc++.h>
using namespace std;

/*
upper_bound(): An iterator to the upper bound position for val in the range.
If no element in the range compares greater than val, the function returns last.

lower_bound():An iterator to the lower bound of val in the range.
If all the element in the range compare less than val, the function returns last.

example:

int myints[] = {10,20,30,30,20,10,10,20};
vector<int>::iterator low,up;
low=lower_bound (v.begin(), v.end(), 20); //          ^
up= upper_bound (v.begin(), v.end(), 20); //

cout << "lower_bound at position " << (low- v.begin()) << '\n';
cout << "upper_bound at position " << (up - v.begin()) << '\n';

output:
lower_bound at position 3
upper_bound at position 6

*/

/*

binary_search(): true if an element equivalent to val is found, and false otherwise

example:

int myints[] = {1,2,3,4,5,4,3,2,1};
sort (v.begin(), v.end());
if (binary_search (v.begin(), v.end(), 3))
    cout << "found!\n";
else cout << "not found.\n";

*/

/*

find():An iterator to the first element in the range that compares equal to val.
If no elements match, the function returns last.

example:
int myints[] = { 10, 20, 30, 40 };
vector<int>::iterator it;

it = find (v.begin(), v.end(), 30);
if (it != v.end())cout << "Element found in v: " << *it << '\n';
else cout << "Element not found in v\n";

output: Element found in v: 30
*/

long long a,b,c,d;
unsigned long long F(long long a,long long b,long long c,long long d,long long t)
{
    return a*t*t*t + b*t*t + c*t + d;
}

//find position of a value.

long long bin_search(long long low,long long high,long long key)
{
    long long ans = 0;
   while(low<=high)
   {
     long long mid=(low+high)/2;

     if(F(a,b,c,d,mid) > key )
     {
         high=mid-1;
     }
     else if( F(a,b,c,d,mid) < key )
     {
         low = mid+1;
     }
     else
     {
         return mid;
     }

   }
    return low;
 }

/*

//find if a value is present.

bool bin_search(int low,int high,int key)
{
   while(low<high)
   {
     int mid=(low+high)/2;
     if(a[mid]<key)
     {
         low=mid+1;
     }
     else if(a[mid]>key)
     {
         high=mid-1;
     }
     else
     {
         return true;
     }
   }
   return false;
 }

 */

int main()
{
    int t;
    long long k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&k);

        cout<<bin_search(1,1000000,k)-1<<endl;
    }
}

