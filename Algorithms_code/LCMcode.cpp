#include<bits/stdc++.h>
using namespace std;
int dp[1120][1120];
string a,b;
int LCS(int i,int j){
if(i==0 || j==0)
    return 0;
if(dp[i][j]!=-1){
    return dp[i][j];
}
if(a[i-1]==b[j-1]){
    dp[i][j]=1+LCS(i-1,j-1);
}
else{
    int a=LCS(i-1,j);
    int b=LCS(i,j-1);
    if(a>b){
        dp[i][j]=a;
    }
    else{
        dp[i][j]=b;
    }
}
return dp[i][j];
}
int main(){
int n,x,y,k;
while(getline(cin,a)){
        getline(cin,b);
    memset(dp,-1,sizeof(dp));
    x=a.size();
    y=b.size();
    k=LCS(x,y);
   cout<<k<<endl;
}

}


