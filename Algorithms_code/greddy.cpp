#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n,x;
int a[100000];
cin>>t;
while(t--){
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    long long int cn=0,res=0;
    for(int i=0;i<n;i++){
            res+=a[i];
        if(res<=x){
            cn++;
        }
    else{
        break;
    }
    }
    cout<<cn<<endl;
}

}
