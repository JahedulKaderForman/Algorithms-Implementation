#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define setz(a) memset(a, 0, sizeof(a))
using namespace std;
vector<int>adj[10005];
int visited[10005],start_time[10005],low_time[10005],parent[10005],tim=0,child_count=0,v,root,total;

void Articulationpoin(int u)
{
    visited[u]=1;
    start_time[u]=tim;
    low_time[u]=tim;
    tim++;
    bool isArti =false;
    for(int i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];   /// adj of each node u
        if(v==parent[u])
            continue;
        if(!visited[v])     /// if unvisited tree edge
        {
            if(u==root)child_count++;
            parent[v]=u;
            Articulationpoin(v);

            int k=adj[u][i];      /// it's important adj[u][i] save again new variable
            if(start_time[u]<=low_time[k])   ///check condition start_time(u)<= low_time(v)
                isArti=true;
            else
                low_time[u]=min(low_time[u],low_time[k]); /// low_time[u]=min(low_time[u],low_time[v]

        }

        else
        {
            low_time[u]=min(low_time[u],start_time[v]);  /// else u is visited that means back edge then low_time[u]=min(low_time[u],start_time[v])
        }
    }
    if((parent[u]==-1 && child_count>=2)||(parent[u]!=-1 && isArti)) /// for count Articulation point
    {
        total++;
    }
}

int main()
{
    int node,edge,x,y,t;
    cin>>t;
    for(int j=1; j<=t; j++)
    {
        cin>>node>>edge;
        setz(visited);
        setz(parent);
        setz(start_time);
        setz(low_time);
        total=0;
        tim=0;
        for(int k=1; k<=edge; k++)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i=1; i<=node; i++)
        {
            if(!visited[i])
            {
                  child_count=0;
                parent[i]=-1; /// for root node assing null
                root=i;         /// save root node
                Articulationpoin(i); /// call dfs
            }
        }
        printf("Case %d: ",j);
        cout<<total<<endl;
        for(int i=1; i<=node; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                adj[i].clear();
            }
        }
    }
}

