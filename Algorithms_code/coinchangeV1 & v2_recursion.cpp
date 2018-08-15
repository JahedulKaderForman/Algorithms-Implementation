#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int c[6]={1,5,10,25,50};
ll v[10][8000];
int coin(int n){
for(int i=0;i<=5;i++){
    v[i][0]=1;
}
for(int i=1;i<=n;i++){
    v[0][i]=0;
}
for(int i=1;i<=5;i++){
    for(int j=1;j<=n;j++){
        if(c[i-1]<=j){
            v[i][j]=v[i-1][j]+v[i][j-c[i-1]];
        }
        else{
            v[i][j]=v[i-1][j];
        }
    }
}
printf("%lld\n",v[5][n]);

}
int main(){
int x;
while(scanf("%d",&x)!=EOF){
coin(x);
}
}
