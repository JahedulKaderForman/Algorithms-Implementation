#include <bits/stdc++.h>
using namespace std;
#define pb(a) push_back(a)
#define setz(a) memset(a, 0, sizeof(a))
#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
typedef long long LL;
typedef unsigned long long uLL;
int visited[1000002],s,flag;
vector<int>vs;
vector<int>adj[1000002];
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
vs.pb(u);
}
int main(){
int n,e,x,y;
while(cin>>n>>e){
if(n==0 && e==0)
break;
setz(visited);
vs.clear();
while(e--){
    isc2(x,y);
    adj[x].pb(y);
}
flag=0;
dfs(1);
if(flag==1)
    cout<<"IMPOSSIBLE"<<endl;
else{
    vs.clear();
    setz(visited);
    for(int i=1;i<=n;i++){
    if(!visited[i]){
        dfs(i);
    }
    }
for(int i=vs.size()-1;i>=0;i--){
    printf("%d\n",vs[i]);
}
}
for(int i=1;i<=n;i++){
    adj[i].clear();
}
}
}






