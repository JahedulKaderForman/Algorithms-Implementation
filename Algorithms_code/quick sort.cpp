#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[1000]= {'\0'};

int Partition(int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }

    }
    swap(a[i+1],a[r]);
    return (i+1);
}
void quicksort(int p,int r)
{
    if(p<r)
    {
        int q=Partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}

int main()
{
    int r,p=1,i,j;
    cin>>r;
    for(i=1; i<=r; i++)
    {
        cin>>a[i];
    }
    quicksort(p,r);
    for(i=1; i<=r; i++)
    {
        cout<<a[i]<<" ";
    }
}
