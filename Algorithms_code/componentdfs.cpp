#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int visited[100];
void dfs(int u){
int v;
visited[u]=1;
for(int j=0;j<adj[u].size();j++){
    v=adj[u][j];
    if(visited[v]==0){
        cout<<v<<" ";
        dfs(v);
    }
}
}
int main(){
int edge,node,x,y;
cin>>edge>>node;
for(int i=0;i<edge;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
int num=1,component=0;
for(int i=0;i<node;i++){
    if(visited[i]==0){
        component++;

        printf("Cc %d:",num);
        cout<<i<<" ";
        dfs(i);
        cout<<endl;
        num++;

    }

}
cout<<"component "<<component<<endl;

}
