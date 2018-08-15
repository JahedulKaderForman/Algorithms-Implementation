#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
int t,n,cn=1,ln,j,i;
cin>>t;
for(int k=1;k<=t;k++){
cn=1;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(i=1;i<n;i++){
    if(a[i]<a[i-1]){
        ln=i;
        break;
    }
}
ln=i;
for(j=n-1;j>=ln;j--){
    if(a[j]>a[j-1]){
        cn++;
    }
    else{
        break;
    }
}
cout<<ln<<" "<<j<<endl;
printf("Case %d: ",k);
if(ln==n)
    cout<<0<<endl;
else if(j==ln){
    cout<<ln<<endl;
}
else cout<<"x"<<endl;
}



}
