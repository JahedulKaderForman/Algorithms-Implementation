#include<iostream>
#include<deque>
#include<cctype>
#include<string>
using namespace std;
int display(deque<string>arr,string value){
for(int i=0;i<arr.size();i++){
    if(arr.at(i)==(value)){
        return i;
    }
}

}
int main(){
deque<string>v;
v.push_back("azad");
v.push_back("bzad");
v.push_back("ozad");
v.push_back("jzad");
string name;
cin>>name;
int pos=display(v,name);
if(pos>-1){
    cout<<pos;
}





}
