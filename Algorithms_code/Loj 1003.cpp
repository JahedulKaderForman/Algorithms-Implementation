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
int flag,visited[10005],vis[10005];
vector<int>adj[10005];
map<string,int>mp;
void dfs(int u){
visited[u]=1;
if(flag==1)
    return;
for(int i=0;i<adj[u].size();i++){
    int v=adj[u][i];
    if(visited[v]==1){
        flag=1;
        return ;
    }
    if(visited[v]==0){
        dfs(v);
    }
}
visited[u]=2;
}
int main(){
int test,e;
cin>>test;
for(int i=1;i<=test;i++){
    string x,y;
        isc(e);
        setz(vis);
        setz(visited);
    int k=1;
    for(int j=1;j<=e;j++){
        cin>>x;
        cin>>y;
        if(vis[mp[x]]==0){
            mp[x]=k;
            k++;
            vis[mp[x]]=1;
        }
        if(vis[mp[y]]==0){
            mp[y]=k;
            k++;
            vis[mp[y]]=1;
        }
        adj[mp[x]].pb(mp[y]);
    }
    flag=0;
    for(int j=1;j<k;j++){
        if(!visited[j]){
            dfs(j);
            if(flag==1)
                break;
        }
    }
    printf("Case %d: ",i);
    if(flag==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    for(int j=1;j<k;j++)
        adj[j].clear();
    mp.clear();

}



}
