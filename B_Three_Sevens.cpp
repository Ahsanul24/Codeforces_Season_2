// IN THE NAME OF ALLAH
// Coded by Ahsanul Imam
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int  MOD = 1000000007;
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define bit(a) __builtin_popcountll(a)
#define w(x) while (x--)
#define test int t; cin>>t; for (int i = 0; i < t; i++)
#define loop for (int i = 0; i < n; i++)
#define print(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pi 2*acos(0.0)
#define pr pair<int, int>
#define Ahsanul (ios_base::sync_with_stdio(false), cin.tie(NULL))
vector<pr>knight_posible{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};//knight moves
vector<pr>posible{{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};//eight direction moves;
int power(int a,int b){int res=1;while (b){if (b&1){res=(res*1ll*a)%MOD;}a=(a*1ll*a)%MOD;b>>=1;}return res;}
void solve()
{
    int d; cin>>d;
    vi day(50000,-1);
    map<int,int>last;
    for(int i=1;i<=d;i++)
    {
        int x; cin>>x;
        for(int j=1;j<=x;j++)
        {
            int y; cin>>y;
            last[y]=i;
        }
    }
    vi res(d+1,-1);
    for(auto &[x,y]:last)
    {
        if(res[y]==-1)
        {
            res[y]=x;
        }
    }
    for(int i=1;i<=d;i++)
    {
        if(res[i]==-1)
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=1;i<=d;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    test
    solve();
}