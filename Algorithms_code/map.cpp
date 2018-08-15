#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
map<string,int>:: iterator it;
int main(){
int t;
string s;
cin>>t;
cin.ignore();
while(t--){
    cin>>s;
    m[s]++;
}
int sum=0,temp=0;
for(it=m.begin();it!=m.end();it++){
        int n=it->second;
        if(n>=temp){
            if(n==temp){
                sum+=n;
            }
            else{
                sum=n;
            }
            temp=n;
        }

}
cout<<sum<<endl;
m.clear();
}
