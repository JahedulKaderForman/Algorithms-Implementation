#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

LL a[1000];
int main()
{
    LL sum;
    int n;
    for(int i=2; i<=100; i+=2)
    {
        sum=0;
        for(int j=i; j<=100; j+=i)
        {
            a[j]+=i;
        }
    }
    for(int i=1; i<20; i++)
    {
        cout<<a[i]<<endl;
    }
}
