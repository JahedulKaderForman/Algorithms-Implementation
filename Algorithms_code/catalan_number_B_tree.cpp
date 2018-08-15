#include<bits/stdc++.h>
using namespace std;
#define uLL unsigned long long int
#define M 100000007

uLL f[10003];
void fact(){
f[0]=1;
for(int i=1;i<10002;i++){
    f[i]=((f[i-1]%M)*(i%M))%M;
}
}

uLL modinverse(uLL a,uLL b){
    uLL ret;
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ret=modinverse(a,b/2);
        return (((ret%M)*(ret%M))%M);
    }
    else{
        return((a%M)*(modinverse(a,b-1)%M))%M;
    }
}

int main(){
fact();
int n;
uLL x,y,z,ans;
scanf("%d",&n);
///main formula (1/n+1) *( 2n!/n!*n!)
/// so we can write this by doing modularinverse (n+1) * n! * n! * 2n!
x=modinverse(n+1,M-2); /// find modularinverse of n+1
y=modinverse(f[n],M-2);/// find modularinverse of n!
z=f[2*n]; /// find 2n!
y=((y%M)*(y%M))%M;   /// n!*n!
ans=((x%M)*(y%M))%M; /// (n+1)*y
ans=((z%M)*(ans%M))%M; /// 2n! * ans
printf("%llu\n",ans);
}

