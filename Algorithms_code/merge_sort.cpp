#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[10000]= {'\0'};

void merges(int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j,k;
    int L[n1+1],R[n2+1];
    for(i=1; i<=n1; i++)
    {
        L[i]=a[p+i-1];
    }
    for(j=1; j<=n2; j++)
    {
        R[j]=a[q+j];
    }

    L[n1+1]=2000000000;
    R[n2+1]=2000000000;
    i=1;
    j=1;
    for(k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
    }
}

void merge_sort(int p,int r)
{

    if(p<r)
    {
        int  q=(p+r)/2;
        merge_sort(p,q);
        merge_sort(q+1,r);
        merges(p,q,r);
    }
}
int main()
{
    int p=1,r,i;
    cin>>r;
    for(i=1; i<=r; i++)
        cin>>a[i];
    merge_sort(p,r);
    for(i=1; i<=r; i++)
        cout<<a[i]<<" ";
}
