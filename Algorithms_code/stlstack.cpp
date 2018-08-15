#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>st;
    int n;
    for(int i=0;i<5;i++){
        cin>>n;
        st.push(n);
    }
    while(!st.empty()){
        cout<<st.front()<<" ";
        st.pop();
    }

}
