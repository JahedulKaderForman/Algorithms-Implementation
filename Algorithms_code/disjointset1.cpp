/// uva 10685 by disjoin set.

#include<bits/stdc++.h>
using namespace std;
int parent[100004],cn[100004],n,visited[100004];
map<string,int>mp;
map<string,int>:: iterator it;
int find_frnd(int x)
{
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find_frnd(parent[x]);

}
void uni(int a,int b)
{
    cn[b]+=cn[a];
    parent[a]=parent[b];
    printf("%d\n",cn[b]);
}
int main()
{
    int t,v;
    string x,y;
    cin>>t;
    while(t--)
    {
        mp.clear();
         memset(cn,0,sizeof(cn));
         memset(parent,0,sizeof(parent));
         memset(visited,0,sizeof(visited));
        cin>>n;
        int k=1;
        for(int j=1; j<=n; j++)
        {
            int flag1=0,flag2=0;
            cin>>x;
            cin>>y;
            if(visited[mp[x]]==0){
             mp[x]=k;
             parent[k]=k;
             cn[k]=1;
             k++;
             visited[mp[x]]=1;
            }
             if(visited[mp[y]]==0){
                mp[y]=k;
                parent[k]=k;
                cn[k]=1;
                k++;
                visited[mp[y]]=1;
             }
            int pa=find_frnd(mp[x]);
            int pb=find_frnd(mp[y]);
            if(pa != pb)
            {
                uni(pa, pb);
            }
            else{
                printf("%d\n",cn[pa]);
            }
        }

    }

}


