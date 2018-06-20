#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[100];

    int n,h,m,sec,speed = 0,nowspeed,nowtime,prevtime = 0;

    double dist = 0;

    while( cin.getline(s,sizeof(s)) )
    {
        n = sscanf(s,"%d:%d:%d %d",&h,&m,&sec,&nowspeed);

        nowtime = h*3600 + m*60 + sec;

        dist = dist + ( nowtime - prevtime )*speed;

        prevtime = nowtime;

        if( n == 3 )
        {
            printf("%02d:%02d:%02d %0.2lf km\n",h,m,sec,dist/3600);
        }
        else if( n == 4 )
        {
            speed = nowspeed;
        }
    }
}
