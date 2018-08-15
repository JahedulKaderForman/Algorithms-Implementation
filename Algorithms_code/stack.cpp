#include<iostream>
using namespace std;
int stack[10];
int stackSize=5,top=-1;

void print(){
for(int i=0;i<=top;i++){
    cout<<stack[i]<<" ";
}
cout<<endl;
}

void push(int y)
{
         if(top>stackSize)
        {
                cout<<"stack full"<<endl;
                return;
        }
        else
       {
              top++;
              stack[top]=y;
        }
}
int pop()
{
         int a;
         if(top<=0)
         {
                cout<<"stack is empty"<<endl;
                return 0;
         }
         else
         {
                a=stack[top];
                top--;
          }
          return(a);
}

int main(){
push(10);
push(20);
push(30);
push(40);
print();
pop();
pop();
print();

}
