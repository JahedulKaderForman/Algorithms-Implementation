#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 11
ll F(ll N,ll P)
{
    ll ret;
	if(P==0) return 1;
	if(P%2==0)
	{
		ll ret=F(N,P/2);
		return ((ret%M)*(ret%M))%M;
	}
	else {
        ret=((N%M)*(F(N,P-1)%M))%M;
        return ret;
	}

}
int main()
{
cout<<F(2,1000)<<endl;
}




