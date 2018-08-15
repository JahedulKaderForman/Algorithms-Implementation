/// cycle find for undirected graph.
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int visited[100];
int n,e,v,flag=0;
int s;
int dfs(int u,int node){
visited[u]=1;
if(flag==1)
    return 0;
    for(int j=0;j<adj[u].size();j++){
            v=adj[u][j];
        if(visited[v]==1 && v!=node){
            flag=1;
            return 0;
        }
        else if(visited[v]==0){
            dfs(v,u);
        }
    }
}
int main(){
cin>>n>>e;
int cn=0,x,y;
for(int i=0;i<e;i++){
    cin>>x>>y;
    adj[x].push_back(y);
     adj[y].push_back(x);
}
dfs(1,-1);
if(flag==1){
        cout<<"Cycle found"<<endl;
}
else{
        cout<<"Cycle not found"<<endl;
}


}

