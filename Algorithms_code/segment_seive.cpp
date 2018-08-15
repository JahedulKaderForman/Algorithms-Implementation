#include <bits/stdc++.h>
using namespace std;

#define setz(a) memset(a, 0, sizeof(a))
typedef unsigned long long uLL;
vector<int>prime;
int mark[1000002];
int arr[100005];

void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(int i=4; i<=n; i+=2)
    {
        mark[i]=1;
    }
    prime.push_back(2);
    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i<=limit)
            {
                for(int j=i*i; j<=n; j+=i*2)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
void segment(int a,int b)
{
    if(a==1)
        a++;
    int srqtn=sqrt(b);
    int j,p;
    setz(arr);
    for(int i=0; i<prime.size() && prime[i]<=srqtn; i++)
    {
        p=prime[i];
        j=p*p;
        if(j<a)
            j=((a+p-1)/p)*p;
        for(int k=j; k<=b; k+=p)
        {
            arr[k-a]=1;
        }

    }

    for(int i=a; i<=b; i++)
    {
        if(arr[i-a]==0)
        {
            printf("%d\n",i);
        }
    }
}

int main()
{
    sieve(100005);
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        segment(x,y);
    }
}
