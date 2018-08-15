#include<bits/stdc++.h>
#define mx 100009
using namespace std;
int tree[mx*3],arr[mx];
void init(int node,int b,int e){
if(b==e){
    tree[node]=arr[b];
    return;
}
int left=node*2;
int right=(node*2)+1;
int mid=(b+e)/2;
init(left,b,mid);
init(right,mid+1,e);
if(tree[left]>tree[right]){
   tree[node]=tree[right];
}
else
   tree[node]= tree[left];
}

int query(int node,int b,int e,int i,int j){
if(i>e || j<b){
    return 100000000;
}
if(b>=i && e<=j){
    return tree[node];
}
int left=node*2;
int right=(node*2)+1;
int mid=(b+e)/2;
int p1=query(left,b,mid,i,j);
int p2=query(right,mid+1,e,i,j);
if(p1>p2)
return p2;
else
return p1;
}


void update(int node,int b,int e,int i,int newvalu){
if(i>e || i<b){
    return ;
}
if(b>=i && e<=i){
    tree[node]=newvalu;
    return;
}
int left=node*2;
int right=(node*2)+1;
int mid=(b+e)/2;
update(left,b,mid,i,newvalu);
update(right,mid+1,e,i,newvalu);
if(tree[left]>tree[right]){
   tree[node]=tree[right];
}
else
   tree[node]= tree[left];
}


int main(){
int n,x,y,t,q;
scanf("%d",&t);
for(int i=1;i<=t;i++){
    scanf("%d%d",&n,&q);
for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
}
init(1,1,n);
printf("Case %d:\n",i);
while(q--){
    scanf("%d%d",&x,&y);
    printf("%d\n",query(1, 1, n, x, y));
}
}
}

