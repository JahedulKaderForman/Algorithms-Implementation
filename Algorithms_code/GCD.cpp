#include<bits/stdc++.h>
using namespace std;
set<string>m;
set<string>:: iterator it;
int a[26];
int main(){
int t;
string s,y;
cin>>t;
cin.ignore();
while(t--){
    cin>>s;
    m.insert(s);
}
int temp=0,ans;
for(it= m.begin();it!=m.end();it++){
    y=*it;
    memset(a,0,sizeof a);
    for(int i=0;i<y.size();i++){
        a[y[i]-'a']++;
    }
   vector<int>v(a,a+26);
   int m=*max_element(v.begin(),v.end());
   if(m>=temp){
    if(m==temp){
        ans+=m;
    }
    else{
        ans=m;
    }
    temp=m;
   }
}
cout<<ans<<endl;

}
