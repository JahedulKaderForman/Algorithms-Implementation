#include <bits/stdc++.h>
#include<bitset>
using namespace std;
#define ft    int t; scanf("%d", &t); for(int c=1; c<=t; c++)
#define nl printf("\n")
#define pb(a) push_back(a)
#define n 10000004
#define ll long long int
bitset<10000010>mark;
vector<int>p;
void prime(){
mark.set();
mark[0]=mark[1]=0;
for(ll i=2;i<=n;i++){
    if(mark[i]){
        for(ll j=i*i;j<=n;j+=i){
            mark[j]=0;
        }
        p.pb((int)i);
    }
}
}
int main(){
prime();
int m;
ft{
scanf("%d",&m);
int cn=0,temp;
for(int i=0;i<p.size();i++){
    temp=m-p[i];
    if(p[i]>m)
        break;
    if(temp>=p[i] && mark[temp]){
        cn++;
    }
}
printf("Case %d: %d\n",c,cn);
}
}
