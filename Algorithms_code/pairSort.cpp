#include <bits/stdc++.h>
using namespace std;

bool sortbysecond(const pair<int,int>&a,const pair<int,int>&b){
return (a.second<b.second);
}

int main()
{
    int n, a, b;
    vector< pair<int, int> > A;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b),
              A.push_back(make_pair(a,b));
    }
    /// sort by first element
    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
    {
        cout<<A[i].first<<" "<<A[i].second<<endl;
    }
     /// sort by second element
    sort(A.begin(), A.end(),sortbysecond);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i].first<<" "<<A[i].second<<endl;
    }
}

