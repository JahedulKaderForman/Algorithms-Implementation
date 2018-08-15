#include <bits/stdc++.h>
using namespace std;
#define setz(a) memset(a, 0, sizeof(a))
#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
#define isc3(a,b,c) scanf("%d%d%d", &a,&b,&c)
typedef long long int ll;
typedef unsigned long long ull;
#define mx 100005

struct{
ll toggle,on;
}tree[4*mx];
void propagat(int n,int L,int R){
int mid=(L+R)/2;
int left=n<<1;
int right=(n<<1)+1;
tree[n].toggle=0;
tree[left].toggle^=1;
tree[right].toggle^=1;
tree[left].on=mid-L+1-tree[left].on;
tree[right].on=R-(mid+1)+1-tree[right].on;
}
void update(int n,int L,int R,int l,int r){
if(L>r || R<l)
    return;
if(L>=l && R<=r){
    tree[n].toggle^=1;
    tree[n].on=(R-L+1)-tree[n].on;
    return;
}
if(tree[n].toggle){
    propagat(n,L,R);
}
int mid=(L+R)/2;
update(n<<1,L,mid,l,r);
update((n<<1)+1,mid+1,R,l,r);
tree[n].on=tree[n<<1].on+tree[(n<<1)+1].on;
}
ll  quary(int n,int L,int R,int l,int r){
if(L>r || R<l)
    return 0;
if(L>=l && R<=r){
   return tree[n].on;
}
if(tree[n].toggle){
    propagat(n,L,R);
}
int mid=(L+R)/2;
ll x=quary(n<<1,L,mid,l,r);
ll y=quary((n<<1)+1,mid+1,R,l,r);
return x+y;
}
int main()
{
    int m,n,x,y,z,ans;
    isc2(m,n);
    while(n--){
        isc3(x,y,z);
        if(x==0){
            update(1,1,m,y,z);
        }
        else{
            ans=quary(1,1,m,y,z);
            cout<<ans<<endl;
        }
    }

}





