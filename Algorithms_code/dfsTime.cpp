#include <bits/stdc++.h>

#define nl printf("\n")
#define pb(a) push_back(a)
#define sz(a) sizeof(a)
#define setz(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
#define lsc(a) scanf("%ld", &a)
#define lsc2(a,b) scanf("%ld%ld", &a,&b)
#define llsc(a) scanf("%lld", &a)

#define ipf(a) printf("%d", a)
#define lpf(a) printf("%ld", a)
#define llpf(a) printf("%lld", a)

#define dsc(a) scanf("%lf", &a)

#define dpf2(a) printf("%.2f", a)
#define dpf3(a) printf("%.3f", a)

#define spf(a) printf("%s", a)

//Case printing
#define casepf(a) printf("Case %d: ", a)
#define cspf(a, b) printf("Case %d: %s\n", a,b)


#define fl(a) floor(a)
#define cl(a) ceil(a)


#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long uLL;

template<class T>
T cmpfunc(const void * a, const void * b)
{
   return ( *(T*)a - *(T*)b );
}
//int item = *((int*) bsearch (&key, name_of_array, noOfitems, sizeof (int), cmpfunc));

template <class T>
inline T gcd(T x,T y){
    T mod;
    while(x%y){
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

#define NODES 200005
int n, query;
map<int,vector<int> > nodes;

int dp[NODES], start[NODES], ending[NODES];

void dfs(int box){
    dp[box] = 1;
    if(nodes[box].size()<1) return;
    for(int i=0;i<nodes[box].size();i++){
        int a = nodes[box][i];
        dfs(a);
        dp[box]+= dp[a];
    }
}

int timeCount;
void setTime(int k){

    start[k] = ++timeCount;
//    printf("start[%d] = %d\n", k,timeCount);
    if(nodes[k].size()<1){
        ending[k] = ++timeCount;
//        printf("end[%d] = %d\n", k,timeCount);
        return;
    }

    for(int j=0; j<nodes[k].size(); j++){
        int a = nodes[k][j];
        setTime(a);
//        ending[a] = ++timeCount;
//        printf("end[%d] = %d\n", a,timeCount);

    }
    ending[k] = ++timeCount;
//    printf("end[%d] = %d\n", k,timeCount);
}

int main(){

    isc(n);
    for(int i=1;i<=n;i++){
        int key;
        isc(key);
        nodes[key].pb(i);
    }
    for(int i=0; i<nodes[0].size();i++)
        dfs(nodes[0][i]);
    for(int i=0; i<nodes[0].size();i++)
        setTime(nodes[0][i]);

    isc(query);
    bool flags[NODES];
    int queries[100];
    for(int i =1;i<=query;i++){
        setz(flags);
        int m;
        isc(m);

        for(int k=1; k<=m; k++){
            isc(queries[k]);
        }
//        for(int k=1; k<=m; k++)
//            printf("query[%d] = %d\n", k, queries[k]);
        for(int k=1; k<=m; k++)
                for(int p=1; p<=m;p++){
//                    printf("Start[%d] = %d  End[%d] = %d\n", k, start[queries[k]], k, ending[queries[k]]);
//                    printf("Start[%d] = %d  End[%d] = %d\n", p, start[queries[p]], p, ending[queries[p]]);
                    if(start[queries[p]]<start[queries[k]] && ending[queries[k]]<ending[queries[p]]){
                        flags[queries[k]] = true;
                        break;
                    }
                }
        //for(int k=1; k<=n; k++) printf("Start[%d] = %d  End[%d] = %d\n", k, start[k], k, ending[k]);
//        for(int k=1; k<=n; k++)
//            printf("f[%d] = %d\n", k, flags[k]);
        int counter=0;
        for(int k=1; k<=m; k++)
            if(flags[queries[k]]==0)
                counter+=dp[queries[k]];

        ipf(counter);nl;
    }

return 0;
}


