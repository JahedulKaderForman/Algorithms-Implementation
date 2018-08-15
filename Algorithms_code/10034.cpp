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

pair<int, pair<double,double> >p[10000];
pair<double ,pair<int, int> >v[10000];
int parent[1000],n;
void init(){
for(int i=1;i<=n;i++)
    parent[i]=i;
}
int root(int x){
if(parent[x]==x)
    return x;
else
   return parent[x]=root(parent[x]);

}
void uni(int x,int y){
    int p=root(x);
    int q=root(y);
    parent[p]=parent[q];
}
double kruska(int k){
init();
double cost=0;
for(int i=0;i<k;i++){
    int x=v[i].second.first;
    int y=v[i].second.second;
    if(root(x)!=root(y)){
        cost+=v[i].first;
        uni(x,y);
    }
}
return cost;
}
int main(){

ft{
double x,y,w1,w2,z1,z2,temp,res;
cin>>n;
for(int i=0;i<n;i++){
    cin>>x>>y;
    p[i]=mp(i+1,mp(x,y));
}
int k=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
            w1=p[i].second.first;
            z1=p[i].second.second;
            w2=p[j].second.first;
            z2=p[j].second.second;
            temp=sqrt(((w1-w2)*(w1-w2))+((z1-z2)*(z1-z2)));
        v[k]=mp(temp,mp(i+1,j+1));
        k++;
    }
}
sort(v,v+k);
res=kruska(k);
if(c!=1)
    nl;
printf("%0.2lf\n",res);

}


}
