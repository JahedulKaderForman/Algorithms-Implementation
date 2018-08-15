#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1200];
int arr[1005];

void divisor(){
    int temp,i,j,count,k;
for(i=1;i<=1000;i++){
        count=0;
    temp=sqrt(i);
    for(j=1;j<=temp;j++){
        if(i%j==0){
            if(j==(i/j)){
                count++;
            }
            else{
                count+=2;
            }
        }
    }
    edge[count].push_back(i);
}
k=1;
for(j=1;j<=1000;j++){
int size=edge[j].size();
for(i=size-1;i>=0;i--){
    arr[k++]=edge[j][i];
}
}
}

int main(){
divisor();
int test,n;
scanf("%d",&test);
for(int i=1;i<=test;i++){
    scanf("%d",&n);
    printf("Case %d: %d\n",i,arr[n]);
}

}
