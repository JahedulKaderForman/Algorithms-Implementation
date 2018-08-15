#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[60][25][1100];
ll coin[200],fix[200];
ll t,n,k;
ll make(ll j,ll cn,ll value){
    if(j==n){
        if(value==0)
            return 1;
        else
            return 0;
    }
    if(dp[j][cn][value]!=-1)
        return dp[j][cn][value];
    ll ret1=0,ret2=0;
    if(cn<fix[j] && value-coin[j]>=0){
        ret1=make(j,cn+1,value-coin[j]);
    }
    ret2=make(j+1,0,value);
    return dp[j][cn][value]=(ret1+ret2)%100000007;
}
int main(){
scanf("%lld",&t);
for(int i=1;i<=t;i++){
        memset(dp,-1,sizeof(dp));
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&coin[i]);
    }
     for(int i=0;i<n;i++){
        scanf("%lld",&fix[i]);
    }
    printf("Case %d: ",i);
    cout<<make(0,0,k)<<endl;


}


}
