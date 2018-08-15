///minimum editdistance to make palindrome by operation insert,delete,replace

#include<bits/stdc++.h>
using namespace std;
string x,y;
int dp[1010][1010],dir[1010][1010];
int edit(int n){
    for(int i=0;i<=n;i++){
        dp[0][i]=i;
    }
     for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1];
                dir[i][j]=1;
            }
            else{
                    if(dp[i][j-1]>=dp[i-1][j]){
                        dir[i][j]=2;
                    }
                    else{
                       dir[i][j]=3;
                    }
                dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;

            }
        }
    }
    return dp[n][n];
}
int main(){
int t,a,b;
cin>>t;
cin.ignore();
for(int i=1;i<=t;i++){
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    getline(cin,x);
    y=x;
    reverse(y.begin(),y.end());
    a=x.size();
    b=edit(a);
    printf("Case %d: %d\n",i,b/2);

}
}

