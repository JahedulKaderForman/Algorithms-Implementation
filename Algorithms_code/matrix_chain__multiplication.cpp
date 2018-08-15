#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int m[100][100]= {'\0'},s[100][100]= {'\0'},p[100]= {'\0'},length_p;

void matrix_chain_order()
{
    int n=length_p-1;
    for(int i=1; i<=n; i++)
    {
        m[i][i]=0;
    }
    for(int l=2; l<=n; l++)
    {
        for(int i=1; i<=(n-l+1); i++)
        {
            int j=i+l-1;
            m[i][j]=9999999;
            for(int k=i; k<=j-1; k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}
void print_optimal_parens(int i,int j)
{
    if(i==j)
        cout<<'A'<<i;
    else
    {
        cout<<'(';
        print_optimal_parens(i,s[i][j]);
        print_optimal_parens(s[i][j]+1,j);
        cout<<')';
    }
}
int main()
{
    int length_a,j=0,x;
    cin>>length_a;
    for(int i=1; i<=2*length_a; i++)
    {
        cin>>x;
        if(i%2!=0||i==2*length_a)
        {

            p[j]=x;
            j++;
        }
    }
    length_p=j;
    matrix_chain_order();
    print_optimal_parens(1,6);
    /*for(int i=0;i<=7;i++){
      for(int j=0;j<=7;j++){
      cout<<s[i][j]<<" ";}
      cout<<endl;
    }*/

}
