#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[1000]= {'\0'},length,heap_size;

void max_heapify(int i)
{
    int largest;
    int l=2*i;
    int r=2*i+1;
    if((l<=heap_size)&&(a[l]>a[i]))
    {
        largest=l;
    }
    else largest=i;
    if((r<=heap_size)&&(a[r]>a[largest]))
        largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(largest);
    }
}
void build_max_heap()
{
    heap_size=length;
    for(int i=length/2; i>=1; i--)
    {
        max_heapify(i);
    }

}
void heapsort()
{
    build_max_heap();
    for(int i=length; i>=2; i--)
    {
        swap(a[1],a[i]);
        heap_size--;
        max_heapify(1);
    }
}

int main()
{
    cin>>length;
    for(int i=1; i<=length; i++)
        cin>>a[i];
    heapsort();
    for(int i=1; i<=length; i++)
        cout<<a[i]<<" ";
}
