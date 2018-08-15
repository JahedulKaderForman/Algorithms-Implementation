#include <bits/stdc++.h>
using namespace std;

// loop and test case
#define ft    int t; scanf("%d", &t); for(int c=1; c<=t; c++)
#define whilecase while (tc--)
#define eof while (cin >> n)
#define forloop for (pos=1; pos<=tc; pos++)
#define arrayloop for (i=0; i<n; i++)

//memset function
#define setz(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define sf scanf
#define pf printf

// integer input
#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
#define isc3(a,b,c) scanf("%d%d%d", &a,&b,&c)

// long and long long integer input
#define lsc(a) scanf("%ld", &a)
#define lsc2(a,b) scanf("%ld%ld", &a,&b)
#define llsc(a) scanf("%lld", &a)
#define llsc2(a,b) scanf("%lld%lld", &a, &b)
#define llsc3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)

// unsign long long input
#define ullsc(a) scanf("%llu", &a)
#define ullsc2(a,b) scanf("%llu%llu", &a, &b)

// double input
#define dsc(a) scanf("%lf", &a)
#define dpf2(a) printf("%.2f", a)
#define dpf3(a) printf("%.3f", a)

//Case printing
#define casepf(a) printf("Case %d: ", a)
#define casestr(a, b) printf("Case %d: %s\n", a,b)
#define nl printf("\n") //new line

#define fl(a) floor(a)
#define cl(a) ceil(a)


#define pb(a) push_back(a)
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)

typedef long long ll;
typedef unsigned long long ull;
#define mx 100001
string s;
struct node{
int sum;
int minsum;
}tree[3*mx];
void init(int n,int i,int j){
if(i==j){
    tree[n].sum=tree[n].minsum=(s[i]=='(' ? 1 : -1);
    return;
}
int m=(i+j)/2;
init(2*n+1,i,m);
init(2*n+2,m+1,j);
tree[n].sum=tree[2*n+1].sum+tree[2*n+2].sum;
tree[n].minsum=min(tree[2*n+1].minsum,(tree[2*n+1].sum+tree[2*n+2].minsum));
}

void update(int n,int i,int j,int r){
if(r<i || r>j){
    return;
}
if(i==r && j==r){
    tree[n].sum=tree[n].minsum= -tree[n].sum;
    return;
}
int m=(i+j)/2;
update(2*n+1,i,m,r);
update(2*n+2,m+1,j,r);
tree[n].sum=tree[2*n+1].sum+tree[2*n+2].sum;
tree[n].minsum=min(tree[2*n+1].minsum,(tree[2*n+1].sum+tree[2*n+2].minsum));
}
int main(){
while(cin>>s){
    int q,r,l,h,len;
    len=s.size()-1;
    char x;
    init(0,0,len);
    isc(q);
    while(q--){
    scanf("%c",&x);
    if(x=='R'){
    isc(r);
    update(0,0,len,r);
    }
    else{
    isc2(l,h);
    ans=update(0,0,len,l,h);
    printf("%d\n",ans);
    }
    }
}



}

