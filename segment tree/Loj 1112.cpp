#include<bits/stdc++.h>
#define mx 100009
#define ll long long int
using namespace std;
ll tree[mx*3],arr[mx];
void init(ll node,ll b,ll e){
if(b==e){
    tree[node]=arr[b];
    return;
}
ll left=node*2;
ll right=(node*2)+1;
ll mid=(b+e)/2;
init(left,b,mid);
init(right,mid+1,e);
tree[node] = tree[left] + tree[right];
}

ll query(ll node,ll b,ll e,ll i,ll j){
if(i>e || j<b){
    return 0;
}
if(b>=i && e<=j){
    return tree[node];
}
ll left=node*2;
ll right=(node*2)+1;
ll mid=(b+e)/2;
ll p1=query(left,b,mid,i,j);
ll p2=query(right,mid+1,e,i,j);
return p1 + p2;
}


void update(ll node,ll b,ll e,ll i,ll newvalu){
if(i>e || i<b){
    return ;
}
if(b>=i && e<=i){
    tree[node]=tree[node]+newvalu;
    return;
}
ll left=node*2;
ll right=(node*2)+1;
ll mid=(b+e)/2;
update(left,b,mid,i,newvalu);
update(right,mid+1,e,i,newvalu);
tree[node] = tree[left] + tree[right];
}


int main(){
long long int n,x,y,t,q,input,res;
scanf("%lld",&t);
for(int i=1;i<=t;i++){
    scanf("%lld%lld",&n,&q);
for(int i=1;i<=n;i++){
    scanf("%lld",&arr[i]);
}
init(1,1,n);
printf("Case %d:\n",i);
while(q--){
    scanf("%lld",&input);
    if(input==1){
        scanf("%lld",&x);
        res=query(1, 1, n, x+1, x+1);
        printf("%lld\n",res);
        update(1,1,n,x+1,-res);
    }
    else if(input==2){
    scanf("%lld%lld",&x,&y);
    update(1,1,n,x+1,y);
    }
    else{
         scanf("%lld%lld",&x,&y);
          printf("%lld\n",query(1, 1, n, x+1, y+1));
    }
}
}
}


