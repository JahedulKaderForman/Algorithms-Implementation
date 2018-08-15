/// cycle find in undirected graph by disjoin set.

#include <bits/stdc++.h>
using namespace std;
int n;
int parent[1005];
void built (int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
}
int find_parent(int n)
{
    if(parent[n] == -1) return n;
    else return parent[n] = find_parent(parent[n]);
}
void uni(int a,int b)
{
    parent[a]=b;
}
int main()
{
    int m,flag=0;
    cin >> n >> m;   /// number of nodes and edge
    built(n);
    for(int i = 0 ; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        int pa = find_parent(a);
        int pb = find_parent(b);
        if(pa != pb)
        {
           uni(pa, pb);
        }
        else{                  /// if pa == pb then cycle find
           flag=1;
        }
    }
    if(flag==1)
        cout<<"cycle found "<<endl;
    else
        cout<<"No cycle have "<<endl;
}
