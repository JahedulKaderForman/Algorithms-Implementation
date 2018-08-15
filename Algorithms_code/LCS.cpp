#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int b[100][100]= {'\0'},c[100][100]= {'\0'};
string x,y;

void LCS_length()
{
    int m=x.length();
    int n=y.length();
    for(int i=1; i<=m; i++)
    {
        c[i][0]=0;
    }
    for(int j=0; j<=n; j++)
    {
        c[0][j]=0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=0;
            }

        }
    }
}
void print_LCS(int i,int j)
{
    if(i==0||j==0)
    {
        return;
    }
    if(b[i][j]==1)
    {
        print_LCS(i-1,j-1);
        cout<<x[i];
    }
    else if(b[i][j]==2)
    {
        print_LCS(i-1,j);

    }
    else print_LCS(i,j-1);
}
int main()
{

    cin>>x>>y;
    int m=x.length();
    int n=y.length();

    for(int i=m; i>=1; i--)
    {
        x[i]=x[i-1];

    }
    for(int j=n; j>=1; j--)
    {
        y[j]=y[j-1];
    }

    LCS_length();
    print_LCS(m,n);
}
