
#include<bits/stdc++.h>
using namespace std;
int vis[300];
vector<int>adj[205];
void bicolor(int s,int n)
{
    queue<int>q;
    q.push(s);
    vis[s]=1;
    int mini=s;
    int maxi=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int g=adj[u][i];
            if(vis[g]==0)
            {
                vis[g]=vis[g]+1;
                q.push(g);
            }
            else
                vis[g]=vis[g]+1;
        }
    }

    int c=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==3)
            c++;
    }
    if(c%2==0 && c!=1)
        cout<<"BICOLORABLE."<<endl;
    else
        cout<<"NOT BICOLORABLE."<<endl;

}
int main()
{
    int test,t;
    int node,edge;
    while(scanf("%d",&node)==1)
    {
        if(node==0)
            break;
        memset(vis,0,sizeof vis);
        cin>>edge;
        int a,b;
        for(int i=0;i<edge;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bicolor(0,node);
         for(int j=0;j<node;j++)
        {
            adj[j].clear();
        }

    }
    return 0;
}
