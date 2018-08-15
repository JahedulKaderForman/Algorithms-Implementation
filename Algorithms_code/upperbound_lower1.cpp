#include<bits/stdc++.h>
using namespace std;
#define ft    int t; scanf("%d", &t); for(int c=1; c<=t; c++)
#define pi 2 * acos (0.0)
#define nl printf("\n")
#define sz(a) sizeof(a)
#define setz(a) memset(a, 0, sizeof(a))

#define csc(a) scanf("%c", &a)
#define isc(a) scanf("%d", &a)
#define lsc(a) scanf("%ld", &a)
#define llsc(a) scanf("%lld", &a)

#define ipf(a) printf("%d", a)
#define cpf(a) printf("%c", a)
#define lpf(a) printf("%ld", a)
#define llpf(a) printf("%lld", a)

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)


#define dsc(a) scanf("%lf", &a)
#define dpf2(a) printf("%.2f", a)
#define dpf3(a) printf("%.3f", a)
#define spf(a) printf("%s", a)

#define fl(a) floor(a)


#define pb(a) push_back(a)
#define pii pair<int,int >
#define mp(a,b) make_pair(a,b)

typedef long long LL;
typedef unsigned long long uLL;

template <class T>
T gcd(T x,T y)
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

vector<int>arr;
vector<int>:: iterator low,up;
int main()
{
    int n,q,x,y,j=1;
    while(cin>>n>>q){
        if(n==0 && q==0)
            break;
        for(int i=0;i<n;i++){
            isc(x);
            arr.pb(x);
        }
        sort(arr.begin(),arr.end());
        printf("CASE# %d:\n",j);
        for(int i=0;i<q;i++){
            isc(y);
            low=lower_bound(arr.begin(),arr.end(),y);
            up=upper_bound(arr.begin(),arr.end(),y);
            if(up-low!=0){
            low=lower_bound(arr.begin(),arr.end(),0);
            up=lower_bound(arr.begin(),arr.end(),y);
            printf("%d found at %d\n",y,(up-low)+1);
            }
            else{
                printf("%d not found\n",y);
            }

        }
        j++;
        arr.clear();
    }
}


