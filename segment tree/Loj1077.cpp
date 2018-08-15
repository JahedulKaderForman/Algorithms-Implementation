#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b){
if(a%b==0)
    return b;
return gcd(b,a%b);


}
int main(){
long long int n,a,b,c,d,x,y;
cin>>n;
for(int i=1;i<=n;i++){
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
     x=abs(a-c);
     y=abs(b-d);
    printf("Case %d: ",i);
    if(x==0){
        cout<<y+1<<endl;
    }
    else if(y==0){
        cout<<x+1<<endl;
    }
    else if(x==0 && y==0){
        cout<<x+1<<endl;
    }
    else{
    cout<<gcd(x,y)+1<<endl;
    }
}
}
