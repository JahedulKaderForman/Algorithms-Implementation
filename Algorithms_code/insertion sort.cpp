#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[10000]={'\0'},length;
void insertion_sort()
{
    for(int j=1; j<length; j++)
    {
        int key=a[j];
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }

}
int main()
{

    cin>>length;
    for(int i=0; i<length; i++)
        cin>>a[i];
    insertion_sort();
    for(int i=0;i<length;i++)
        cout<<a[i]<<" ";
}
