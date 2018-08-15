#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
vector<int>d;

int main()
{
    int n,s;
    cin>>n;
    int temp=sqrt(n);
    for(int i=1; i<=temp; i++)
    {
        if(n%i==0)
        {
            s=n/i;
            if(s!=i)
            {
                d.push_back(i);
                d.push_back(s);
            }
            else
            {
                d.push_back(s);
            }
        }
    }
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
}
