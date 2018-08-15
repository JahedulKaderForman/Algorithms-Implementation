#include<bits/stdc++.h>
using namespace std;
int main(){
int t,a,b,x,y,c,d;
cin>>t;
for(int i=1;i<=t;i++){
    scanf("%d%d%d%d",&a,&b,&x,&y);
    c=abs(x-a);
    d=abs(y-b);
    printf("Case %d: ",i);
    if(c==d){
        printf("%d\n",1);
    }
    else if((c%2==0 && d%2==0)||(c%2!=0 && d%2!=0)){


        cout<<2<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }

}


}
