#include <bits/stdc++.h>
using namespace std;
int a[10000],lis[10000];
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    lis[i]=1;
}
int ans=1;
for(int j=1;j<n;j++){
    for(int i=0;i<j;i++){
        if(a[i]<=a[j] && lis[i]+1>lis[j]){
            lis[j]=lis[i]+1;
            ans=max(ans,lis[j]);
        }
    }
}
cout<<ans<<endl;
}



