#include <bits/stdc++.h>
using namespace std;

const int mx = 10005;
vector <int> g[mx];
vector <int> r[mx];
vector <int> top;
bool visit[mx];
int comp[mx];
int inDegree[mx];
vector <int> p[mx];
map <string , int> mp;
map <int , string > mp1;
void init (int n)
{
for(int i = 0; i < n; i++)
{
g[i].clear();
r[i].clear();
p[i].clear();
}
memset(visit, false, sizeof visit);
top.clear();
memset(inDegree , 0, sizeof inDegree);
memset(comp, 0, sizeof comp);
mp.clear();
mp1.clear();
}
void dfs1(int u)
{
visit[u] = true;
for(int i = 0; i < g[u].size(); i++)
{
int v = g[u][i];
if(visit[v] == false)
dfs1(v);
}
top.push_back(u);
}
void dfs2(int u , int c)
{
visit[u] = true;
comp[u] = c;

for(int i = 0; i < r[u].size(); i++)
{
int v = r[u][i];
if(visit[v] == false)
{
dfs2(v, c);
}
}
}
int main()
{
int n , e, o = 0;
while(cin >> n >> e)
{
if(n == 0 && e == 0)
break;
o++;
init(n);

int in = 0;
for(int i = 0; i < e; i++)
{
string a, b;
cin >> a >> b;
if(mp.find(a) == mp.end())
mp[a] = in++;
if(mp.find(b) == mp.end())
mp[b] = in++;
g[mp[a]].push_back(mp[b]);
r[mp[b]].push_back(mp[a]);
}

map <string , int > :: iterator it;

for(it = mp.begin(); it != mp.end(); it++)
{
mp1[it->second] = it->first;
}
for(int i = 0; i < n; i++)
{
if(visit[i] == false)
dfs1(i);
}

for(int i = 0 ; i <= n; i++)
{
visit[i] = 0;
}
int cId = 0;
for(int i = top.size() - 1; i >= 0; i--)
{
if(visit[top[i]] == false)
{
dfs2(top[i] , ++cId);
}
}
for(int i = 0; i < n; i++)
{
p[comp[i]].push_back(i);
}
printf("Calling circles for data set %d:\n",o);
for(int i = 1; i <= cId; i++)
{

for(int j = 0; j < p[i].size(); j++)
{
if(j == 0)
{
int x = p[i][j];
cout<<mp1[x];
}
else
{
int x = p[i][j];
cout<<", " << mp1[x];
}

}
printf("\n");

}
cout<<endl;


}
}
