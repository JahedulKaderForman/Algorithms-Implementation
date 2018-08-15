/*
input :
8 12 node and edge
1 2
2 6
2 7
3 7
3 4
4 8
5 2
6 3
6 5
7 6
7 8
8 4
*/

#include<bits/stdc++.h>
using namespace std;
int visited[1000];
vector<int>adj[1000];
vector<int>transpose[10000];
vector<int>vs;
void dfs(int u){
visited[u]=1;
for(int i=0;i<adj[u].size();i++){
    int v=adj[u][i];
    if(visited[v]==0){
        dfs(v);
    }
}
vs.push_back(u);
}
void dfs2(int u){
visited[u]=1;
for(int i=0;i<transpose[u].size();i++){
    int v=transpose[u][i];
    if(visited[v]==0){
        cout<<v;
        dfs2(v);
    }
}
}
int main(){
int n,e,x,y,vs[10000];
while(cin>>n>>e){
        string x,y;
        int k=1;
    for(int i=1;i<=e;i++){
        cin>>x>>y;
    }
}
for(int i=1;i<=e;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    transpose[y].push_back(x);
}
dfs(1);
memset(visited,0,sizeof(visited));
for(int i=vs.size()-1;i>=0;i--)
    if(!visited[vs[i]]){
        cout<<"ss: "<<vs[i];
        dfs2(vs[i]);
        cout<<endl;
    }
}


