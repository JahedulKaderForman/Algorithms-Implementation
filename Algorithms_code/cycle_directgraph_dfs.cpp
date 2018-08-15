/// cycle find for directed graph.
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int visited[100];
int n,e,v,flag=0;
void dfs(int u){
visited[u]=1;
if(flag==1)
    return;
for(int i=0;i<adj[u].size();i++){
    int v=adj[u][i];
    if(visited[v]==1){
        flag=1;
        return;
    }
    else if(visited[v]==0){
        dfs(v);
    }
}
visited[u]=2;
}
int main(){
cin>>n>>e;
int cn=0,x,y;
for(int i=0;i<e;i++){
    cin>>x>>y;
    adj[x].push_back(y);
}
dfs(1);
if(flag==1){
    cout<<"Cycle found"<<endl;
}
else{
    cout<<"Cycle not found"<<endl;
}


}
