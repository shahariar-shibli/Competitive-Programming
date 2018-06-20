#include<bits/stdc++.h>
using namespace std;

int ans [500000 + 5];

int main ()
{
    ans [1] = 1;
    ans [2] = 2;

    int next = 2;

    for ( int i = 3; i <= 500000; i++ ) {
        if ( i < next ) next = 2;
        ans [i] = next;
        next += 2;
    }

    int n;

    while ( scanf ("%d", &n) && n ) {
        printf ("%d\n", ans [n]);
    }

    return 0;
}
