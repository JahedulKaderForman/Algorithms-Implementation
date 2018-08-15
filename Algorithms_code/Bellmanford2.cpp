#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int d[1200];
vector<pii>adj[1100];
int n,e,x,y,w,res;
void init()
{
    for(int i=0; i<n; i++)
    {
        d[i]=99999999999;
    }
    d[0]=0;
}
int bell()
{
    init();
    int v,wt;
    for(int i=0; i<n; i++)
    {
        for(int u=0; u<n; u++)
        {
            for(int j=0; j<adj[u].size(); j++)
            {
                v=adj[u][j].first;
                wt=adj[u][j].second;
                if(i==n-1 && d[v]>d[u]+wt)
                {
                    return 0;
                }
                else if(d[v]>d[u]+wt)
                {
                    d[v]=d[u]+wt;
                }
            }
        }
    }
return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        for(int i=1; i<=e; i++)
        {
            cin>>x>>y>>w;
            adj[x].push_back(pii(y,w));
        }
        res=bell();
        if(res)
        {
            cout<<"not possible"<<endl;
        }
        else
            cout<<"possible"<<endl;
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
    }

}
