#include <bits/stdc++.h>
using namespace std;

// loop and test case
#define ft    int t; scanf("%d", &t); for(int c=1; c<=t; c++)

//memset function
#define setz(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define sf scanf
#define pf printf

// integer input
#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
#define isc3(a,b,c) scanf("%d%d%d", &a,&b,&c)

// long and unsinged long long integer input
#define lsc(a) scanf("%ld", &a)
#define lsc2(a,b) scanf("%ld%ld", &a,&b)
#define llsc(a) scanf("%lld", &a)
#define llsc2(a,b) scanf("%lld%lld", &a, &b)
#define llsc3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define ullsc(a) scanf("%llu", &a)
#define ullsc2(a,b) scanf("%llu%llu", &a, &b)

// double input && output
#define dsc(a) scanf("%lf", &a)
#define dpf2(a) printf("%.2f", a)
#define dpf3(a) printf("%.3f", a)

//print function
#define ipf(a) printf("%d", a)
#define lpf(a) printf("%ld", a)
#define llpf(a) printf("%lld", a)
#define ullpf(a) printf("%llu", a)
#define nl printf("\n")

//Case printing
#define casepf(a) printf("Case %d: ", a)
#define casestr(a, b) printf("Case %d: %s\n", a,b)

//floor && ceil
#define fl(a) floor(a)
#define cl(a) ceil(a)


#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef pair<int, int> pii;


typedef long long int ll;
typedef unsigned long long ull;

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

int main(){
int r,c,e,x,q;
char a[120][120],w;
cin>>r>>c;
cin.ignore();
int flag=1;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>a[i][j];
    }
}
if(r%3!=0 && c%3!=0){
    cout<<"NO"<<endl;
}
else if(r%3==0 && c%3==0){
     flag=0;
    x=r/3;
    w=a[0][0];
    for(int i=0;i<x;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]!=w){
                flag=1;
                break;
            }
        }
    }
    w=a[x][0];
    q=x+(x-1);
     for(int i=x;i<=q;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]!=w){
                flag=1;
                break;
            }
        }
    }
    e=x+x;
    w=a[e][0];
    for(int i=e;i<r;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]!=w){
                flag=1;
                break;
            }
        }
    }
    x=c/3;
    w=a[0][0];
    for(int i=0;i<r;i++){
        for(int j=0;j<x;j++){
               // cout<<a[i][j];
            if(a[i][j]!=w){
                flag=1;
                break;
            }
        }
    }
   // cout<<flag<<endl;
    w=a[0][x];
    //cout<<w<<endl;
    q=x+(x-1);
     for(int i=0;i<r;i++){
        for(int j=x;j<=q;j++){
            if(a[i][j]!=w){
                flag=1;
                break;
            }
        }
    }
    //cout<<flag<<endl;
    e=x+x;
    w=a[0][e];
    for(int i=0;i<r;i++){
        for(int j=e;j<c;j++){
               // cout<<a[i][j]<<endl;
            if(a[i][j]!=w){
                flag=1;
                break;
            }
        }
    }
//cout<<flag<<endl;
if(flag==1){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}

}
else if(r%3==0){
    x=r/3;
    w=a[0][0];
    for(int i=0;i<x;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]!=w){
                flag=0;
                break;
            }
        }
    }
    w=a[x][0];
    q=x+(x-1);
     for(int i=x;i<=q;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]!=w){
                flag=0;
                break;
            }
        }
    }
    e=x+x;
    w=a[e][0];
    for(int i=e;i<r;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]!=w){
                flag=0;
                break;
            }
        }
    }
   if(flag==1){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
}
else{
    x=c/3;
    w=a[0][0];
    for(int i=0;i<r;i++){
        for(int j=0;j<x;j++){
               // cout<<a[i][j];
            if(a[i][j]!=w){
                flag=0;
                break;
            }
        }
    }
   // cout<<flag<<endl;
    w=a[0][x];
    //cout<<w<<endl;
    q=x+(x-1);
     for(int i=0;i<r;i++){
        for(int j=x;j<=q;j++){
            if(a[i][j]!=w){
                flag=0;
                break;
            }
        }
    }
    //cout<<flag<<endl;
    e=x+x;
    w=a[0][e];
    for(int i=0;i<r;i++){
        for(int j=e;j<c;j++){
               // cout<<a[i][j]<<endl;
            if(a[i][j]!=w){
                flag=0;
                break;
            }
        }
    }

if(flag==1){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}

}

}
