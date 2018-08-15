#include<bits/stdc++.h>
using namespace std;
class AlienAndPassword {
public:
int getNumber(string S);
};

int AlienAndPassword ::getNumber(string S) {
set<string>m;
set<string>:: iterator it;
for(int i=0;i<S.size();i++){
        string a;
    for(int j=0;j<S.size();j++){
        if(j!=i){
        a+=s[j];
        }
    }
    m.insert(a);
}
return m.size();
}
