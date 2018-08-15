#include<bits/stdc++.h>
#define mx 100001
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
tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j){
if(i>e || j<b){
    return 0;
}
if(b>=i && e<=j){
    return tree[node];
}
int left=node*2;
int right=(node*2)+1;
int mid=(b+e)/2;
int p1=query(left,b,mid,i,j);
int p2=query(right,mid+1,e,i,j);
return p1+p2;
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
tree[node]=tree[left]+tree[right];
}


int main(){
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>arr[i];
}
init(1,1,n);
cout << query(1, 1, n, 2, 4) << endl;
update(1,1,n,2,1);
cout << query(1, 1, n, 2, 4) << endl;
}
