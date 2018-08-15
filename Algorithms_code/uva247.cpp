#include <bits/stdc++.h>
#define ft    int t; scanf("%d", &t); for(int c=1; c<=t; c++)
#define nl printf("\n")
#define pb(a) push_back(a)
#define sz(a) sizeof(a)
#define setz(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
#define isc3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define lsc(a) scanf("%ld", &a)
#define lsc2(a,b) scanf("%ld%ld", &a,&b)
#define llsc(a) scanf("%lld", &a)
#define llsc2(a,b) scanf("%lld%lld", &a, &b)
#define llsc3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define ullsc(a) scanf("%llu", &a)
#define ullsc2(a,b) scanf("%llu%llu", &a, &b)

#define ipf(a) printf("%d", a)
#define lpf(a) printf("%ld", a)
#define llpf(a) printf("%lld", a)

#define dsc(a) scanf("%lf", &a)

#define dpf2(a) printf("%.2f", a)
#define dpf3(a) printf("%.3f", a)

#define spf(a) printf("%s", a)
#define spf(a) printf("%s", a)

//Case printing
#define casepf(a) printf("Case %d:", a)
#define casestr(a, b) printf("Case %d: %s\n", a,b)

#define fl(a) floor(a)
#define cl(a) ceil(a)

#define mp(a,b) make_pair(a,b)
using namespace std;


typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
typedef unsigned long long uLL;

template <class T>
inline T gcd(T x,T y)
{
    T mod;
    while(x%y)
    {
        mod = x%y;
        x = y;
        y = mod;
    }
    return y;
}

int kdx[] = {2,2,-2,-2,1,-1,1,-1};
int kdy[] = {1,-1,1,-1,2,2,-2,-2};

int edx[] = {1,-1,0,0,1,1,-1,-1};
int edy[] = {0,0,1,-1,1,-1,1,-1};

int fdx[] = {1,-1,0,0};
int fdy[] = {0,0,1,-1};


int visited[1000],vis[1000];
vector<int>adj[1000];
vector<int>transpose[1000];
vector<int>vs;
map<string,int>mp;
map<string,int>:: iterator it;
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
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==v)
                cout<<", "<<it->first;
        }
        dfs2(v);
    }
}
}
int main(){
int n,e,x,y,j=1;
while(cin>>n>>e){
        if(j!=1)
           nl;
        setz(visited);
        if(n==0 && e==0)
        break;
        setz(vis);
        string x,y;
        int k=1;
    for(int i=1;i<=e;i++){
        cin>>x;
        cin>>y;
        if(vis[mp[x]]==0){
        mp[x]=k;
        vis[mp[x]]=1;
        k++;
        }
        if(vis[mp[y]]==0){
        mp[y]=k;
        vis[mp[y]]=1;
        k++;
        }
    adj[mp[x]].push_back(mp[y]);
    transpose[mp[y]].push_back(mp[x]);
    }
    for(int i=1;i<=n;i++){
    if(!visited[i])
       dfs(i);
    }
setz(visited);
printf("Calling circles for data set %d:\n",j);
for(int i=vs.size()-1;i>=0;i--){
        int flag=0;
    if(!visited[vs[i]]){
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==vs[i]){
                flag=1;
                cout<<it->first;
            }
        }
        dfs2(vs[i]);
        if(flag==1)
            nl;
    }
}
for(int i=1;i<=n;i++){
    adj[i].clear();
    transpose[i].clear();
}
mp.clear();
j++;
}



}



