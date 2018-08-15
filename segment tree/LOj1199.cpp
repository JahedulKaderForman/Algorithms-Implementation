#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n,nim,x,grandy;
scanf("%d",&t);
for(int i=1;i<=t;i++){
        int nim=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        grandy=x%3;
        if(grandy==0){
            grandy=3;
        }
        nim ^=grandy;
    }
    printf("Case %d: ",i);
    if(n==1 && nim%3==0){
        cout<<"Alice"<<endl;
    }
    else if(nim==0){
        cout<<"Alice"<<endl;
    }
    else{
        cout<<"Bob"<<endl;
    }
}

}
