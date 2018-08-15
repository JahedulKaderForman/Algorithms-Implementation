#include<bits/stdc++.h>
using namespace std;
int d[3]={1,2,5};/// coin
int c[10];/// store mimimum coin required
int s[10];/// store coin value
int x,coin;
void minimumcoin(int n){
for(int i=0;i<=n;i++){
        int mini=10000000;
    if(i==0){
        c[i]=0;
        s[i]=0;
    }
    else{
    for(int j=0;j<3;j++){
        if(d[j]<=i){
                x=1+c[i-d[j]];
            if(x<mini){
                mini=x;
                coin=j;
            }
        }
    }
    c[i]=mini;
    s[i]=coin;
    }
}
cout<<"Minimum coin required "<<c[n]<<endl;
}

void coinvalue(int A){
cout<<"USE of COIN for MAKE "<<A<<":"<<endl;
int a=A;
while(A>0){
    cout<<d[s[A]]<<endl;
    A=A-d[s[A]];
}
}

int main(){
minimumcoin(6);
coinvalue(6);
}
