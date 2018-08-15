#include<bits/stdc++.h>
using namespace std;

int main(){
int ln,n;
cin>>n;
cin.ignore();
while(n--){
map<int,vector<string> >p;
string s,m;
getline(cin,s);
for(int i=0;i<s.size();i++){
    if(s[i]==' '){
       ln=m.size();
       p[ln].push_back(m);
       m="";
    }
    else{
    m+=s[i];
    }
}
ln=m.size();
p[ln].push_back(m);
for(int j=60;j>=1;j--){
for(int i=0;i<p[j].size();i++){
    cout<<p[j][i]<<" ";
}
}
cout<<endl;
}
}


