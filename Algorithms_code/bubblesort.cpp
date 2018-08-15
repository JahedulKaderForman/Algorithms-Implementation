#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
int n,flag;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
int cn=0;
for(int i=0;i<n;i++){
        flag=0;
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
            flag=1;
            swap(a[i],a[j]);
        }
    }
if(flag==1)
    cn++;
}
cout<<cn<<endl;


}
