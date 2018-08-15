#include <bits/stdc++.h>
using namespace std;

// loop and test case
#define ft    int t; scanf("%d", &t); for(int c=1; c<=t; c++)
#define whilecase while (tc--)
#define eof while (cin >> n)
#define forloop for (pos=1; pos<=tc; pos++)
#define arrayloop for (i=0; i<n; i++)

//memset function
#define setz(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define sf scanf
#define pf printf

// integer input
#define isc(a) scanf("%d", &a)
#define isc2(a,b) scanf("%d%d", &a,&b)
#define isc3(a,b,c) scanf("%d%d%d", &a,&b,&c)

// long and long long integer input
#define lsc(a) scanf("%ld", &a)
#define lsc2(a,b) scanf("%ld%ld", &a,&b)
#define llsc(a) scanf("%lld", &a)
#define llsc2(a,b) scanf("%lld%lld", &a, &b)
#define llsc3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)

// unsign long long input
#define ullsc(a) scanf("%llu", &a)
#define ullsc2(a,b) scanf("%llu%llu", &a, &b)

// double input
#define dsc(a) scanf("%lf", &a)
#define dpf2(a) printf("%.2f", a)
#define dpf3(a) printf("%.3f", a)

//Case printing
#define casepf(a) printf("Case %d: ", a)
#define casestr(a, b) printf("Case %d: %s\n", a,b)
#define nl printf("\n") //new line

#define fl(a) floor(a)
#define cl(a) ceil(a)


#define pb(a) push_back(a)
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)

typedef long long ll;
typedef unsigned long long ull;
#define mx 100002
int tree[mx*3];
string s;
void init(int node,int b,int e)
{
    if(b==e)
    {
        //cout<<s[e-1]<<endl;
        tree[node]=s[e-1]-'0';
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=(node*2)+1;
    init(left,b,mid);
    init(right,mid+1,e);
}
void update(int node,int L,int R,int l,int r)
{
    if(R<l || L>r)
        return;
    if(L>=l && R<=r)
    {
        // cout<<"before "<<node<<" "<<l<<" "<<r<<" "<<tree[node]<<endl;
        tree[node]^=1;
        //cout<<"after "<<tree[node]<<endl;
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=(node*2)+1;
    update(left,L,mid,l,r);
    update(right,mid+1,R,l,r);
}
int qurery(int node,int L,int R,int pos)
{
//cout<<L<<" LR "<<R<<endl;
    if(R<pos || L>pos)
        return 0;
    if(L>=pos && R<=pos)
    {
        //  cout<<"node"<<node<<endl;
        return tree[node];

    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=(node*2)+1;
    if(pos<=mid)
    {
        int p1=qurery(left,L,mid,pos)^tree[node];
        //cout<<"p1 "<<p1<<endl;
        return p1;
    }
    else
    {
        int p2=qurery(right,mid+1,R,pos)^tree[node];
        //cout<<"p2 "<<p2<<endl;
        return p2;
    }

}
int main()
{
    int n,a,b,pos,ln,q;
    char temp;
    cin>>n;
    cin.ignore();
    for(int j=1; j<=n; j++)
    {
        setz(tree);
        getline(cin,s);
        ln=s.size();
        init(1,1,ln);
//    for(int i=8;i<=15;i++){
//        cout<<tree[i]<<endl;
//    }

        printf("Case %d:\n",j);
        scanf("%d",&q);
        getchar();
        //cin.ignore();
        for(int i=1; i<=q; i++)
        {
            scanf("%c ",&temp);

          //  cout<<temp<<endl;

//        cin>>temp;
//        cin.ignore();
//     //   cout<<"t "<<temp<<endl;
            if(temp=='I')
            {
                scanf("%d %d",&a,&b);
                update(1,1,ln,a,b);
            }
            else
            {
                scanf("%d",&pos);
                printf("%d\n",qurery(1,1,ln,pos));
            }
            getchar();

        }
    }
    return 0;
}

