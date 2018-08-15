#include<bits/stdc++.h>
using namespace std;
int prime[30000000],nprime,n=10000000;
int mark[100000000];
void prim(){
    int limit=sqrt((n*1.0)+2);
mark[1]=0;
for(int i=4;i<=n;i+=2){
    mark[i]=1;
}
prime[nprime++]=1;
prime[nprime++]=2;
for(int i=3;i<=n;i++){
    if(!mark[i]){
        prime[nprime++]=i;
        if(i<limit){
            for(int j=i*i;j<=n;j+=i*2){
                mark[j]=1;
            }
        }
    }
}
}
int main(){
prim();
int n,cnrow=0,cncol=0,k=0,j,i;
cin>>n;
for(i=0;i<=n;i++){
    cnrow++;
    i+=prime[k];
    cout<<prime[k]<<endl;
    k++;
    if(i>=n)
        break;
}
cout<<i<<endl;
if(cnrow%2==0){
    for(j=i;j>=prime[cnrow];j--){
        cncol++;
        if(j==n)
            break;
    }
    cout<<cnrow<<" "<<cncol<<endl;
}
else{
        cout<<" z"<<i<<endl;
    for(j=(i+1)-prime[i];j<=prime[i];j++){
        cncol++;
        if(j==n)
            break;
    }
    cout<<cnrow<<" "<<cncol<<endl;
}




}
