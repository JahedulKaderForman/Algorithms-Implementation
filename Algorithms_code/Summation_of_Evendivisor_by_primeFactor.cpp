/// see details in google
#include<bits/stdc++.h>
#define N 10000000
using namespace std;
int mark[10000003];
map<int,int>m;
map<int,int>:: iterator it;
vector<int>p;
void prime()
{
    int limit=sqrt(N)+2;
    for(int i=4; i<=N; i+=2)
    {
        mark[i]=1;
    }
    p.push_back(2);
    for(int i=3; i<=N; i+=2)
    {
        if(mark[i]==0)
        {
            p.push_back(i);
            if(i<=limit)
            {
                for(int j=i*i; j<=N; j+=i)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
void primefactor(int n)
{
    int temp=(int)sqrt(n);
    for(int i=0; p[i]<=temp; i++)
    {
        if(n%p[i]==0)
        {
            while(n%p[i]==0)
            {
                n/=p[i];
                m[p[i]]++;
            }
        }
    }
    if(n>1)
    {
        m[n]=1;
    }


}
int main()
{
    prime();
    int n,sum=1,r;
    cin>>n;
    primefactor(n);
    for(it=m.begin(); it!=m.end(); it++)
    {
        if(it->first==2)
        {
            int temp=0;
            for(int i=1; i<=it->second; i++)
            {
                temp+=round(pow(it->first,i));
            }
            sum*=temp;
        }
        else
        {
            int temp=0;
            for(int i=0; i<=it->second; i++)
            {
                temp+=round(pow(it->first,i));
            }
            sum*=temp;
        }
    }
    cout<<"summation of odd divisor  "<<n<<" is "<<sum<<endl;
}




