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
int a[500005];
int lower(int key,int beg,int ln){
    int index=-1;
    while(beg<=ln){
        int mid=(beg+ln)/2;
        if(key==a[mid]){
            index=mid;
            ln=mid-1;
        }
        else if(key>a[mid]){
            beg=mid+1;
        }
        else{
            ln=mid-1;
        }
    }
    if(index==-1){
        return beg;
    }
    else
    return index;

}
int upper(int key,int beg,int ln){
int index=-1;
    while(beg<=ln){
        int mid=(beg+ln)/2;
        if(key==a[mid]){
            index=mid;
            beg=mid+1;
        }
        else if(key>a[mid]){
            beg=mid+1;
        }
        else{
            ln=mid-1;
        }
    }
    if(index==-1){
        return ln;
    }
    else
    return index;



}
int main(){
int t,n,q,x,y,ans1,ans2,ad;
isc(t);
for(int j=1;j<=t;j++){
isc2(n,q);
for(int i=0;i<n;i++){
    isc(a[i]);
}
sort(a,a+n);
 printf("Case %d:\n",j);
while(q--){
    isc3(x,y,ad);
    ans1=lower(x+ad,0,n-1);
    ans2=upper(y+ad,0,n-1);
    printf("%d\n",(ans2-ans1)+1);
}
}


}
