#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];

struct info{
long long int prop,sum;
}tree[mx*3];

void init(int node,int b,int e){
if(b==e){
    tree[node].sum=arr[b];
    return;
}
int left=node*2;
int right=(node*2)+1;
int mid=(b+e)/2;
init(left,b,mid);
init(right,mid+1,e);
tree[node].sum=tree[left].sum+tree[right].sum;
}

void update(int node,int b,int e,int i,int j,int x){
if(i>e || j<b)
    return;
if(b>=i && e<=j){
    tree[node].sum+=((e-b+1)*x);
    tree[node].prop+=x;
    return;
}
int mid=(b+e)/2;
int left=(node*2);
int right=(node*2)+1;
update(left,b,mid,i,j,x);
update(right,mid+1,e,i,j,x);
tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry=0){
if(i>e || j<b)
    return 0;
if(b>=i && e<=j){
    return tree[node].sum+carry*(e-b+1);
}
int mid=(b+e)/2;
int left=(node*2);
int right=(node*2)+1;
int p1=query(left,b,mid,i,j,carry+tree[node].prop);
int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
return p1+p2;
}
int main(){
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>arr[i];
}
init(1,1,n);
cout << query(1, 1, n, 3, 5,0) << endl;
update(1, 1, n, 3, 5,2);
cout << query(1, 1, n, 3, 5,0) << endl;
}

