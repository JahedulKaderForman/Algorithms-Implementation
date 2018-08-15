#include<bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
vector<int>adj[1000];
vector<int>Ans;
int visited[1000],start_time[1000],low_time[1000],parent[1000],tim=0,child_count=0,v,root;
void Articulationpoin(int u){
visited[u]=1;
start_time[u]=tim;
low_time[u]=tim;
tim++;
bool isArti =false;
for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];   /// adj of each node u
    if(v==parent[u])
        continue;
    if(!visited[v]){    /// if unvisited tree edge
        if(u==root)child_count++;
        parent[v]=u;
        Articulationpoin(v);

        int k=adj[u][i];      /// it's important adj[u][i] save again new variable
        if(start_time[u]<=low_time[k])   ///check condition start_time(u)<= low_time(v)
            isArti=true;
        else
            low_time[u]=min(low_time[u],low_time[k]); ///assing low_time[u]=min(low_time[u],low_time[v]

    }

    else{
        low_time[u]=min(low_time[u],start_time[v]);  /// else u is visited that means back edge then low_time[u]=min(low_time[u],start_time[v])
    }
}

if((parent[u]==-1 && child_count==2)||(parent[u]!=-1 && isArti)){
   Ans.pb(u);
}
}

int main(){
int node,edge,x,y;
cin>>node>>edge;
while(edge--){
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
}
parent[1]=-1; /// for root node assing null
root=1;         /// save root node
Articulationpoin(1); /// call dfs
cout<<"ANS :"<<endl;
for(int i=0;i<Ans.size();i++)
    cout<<Ans[i]<<endl;
}

