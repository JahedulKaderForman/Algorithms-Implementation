#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],c[10000],ans[10000];
int main(){
//freopen("simplin.txt","r",stdin);
//freopen("simpleout.txt","w",stdout);
vector<int>v;
int n,m,i=0;
int k=0;
while(cin>>m){
    b[i]=m;
    c[i]=m;
    vector<int>::iterator it=lower_bound(v.begin(),v.end(),m);
    if(v.end()==it){
        v.push_back(m);
        a[k]=i;       /// save index
        b[a[k]]=a[k-1]; /// assing parent of it's previous following parent
      ///  cout<<a[k]<<endl;
       /// cout<<b[a[k]]<<" val "<<a[k-1]<<endl;
        k++;
    }
    else{
        v[it-v.begin()]=m;
        a[it-v.begin()]=i;         /// save index
        b[a[it-v.begin()]]=a[(it-v.begin())-1];  /// assing parent of it's previous following parent
       /// cout<<a[it-v.begin()]<<endl;
       /// cout<<b[a[it-v.begin()]]<<" val2 "<<a[(it-v.begin())-1]<<endl;
    }
    i++;
}
int temp=a[k-1],x=0;
for(int i=v.size()-1;i>=0;i--){
    ans[x++]=c[temp];
    temp=b[temp];
}
for(int i=x-1;i>=0;i--){
    cout<<ans[i]<<endl;
}
}
