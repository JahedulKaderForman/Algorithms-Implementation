#include<bits/stdc++.h>
using namespace std;

int main(){
string s;
getline(cin,s);
int i=s.find("ustc");
while(i!=-1){
    s.erase(i,4); /// index number and how many words need erase.
    s.insert(i,"iiuc");/// index number and which string need to insert.
    i=s.find("ustc");
}
cout<<s<<endl;
}
