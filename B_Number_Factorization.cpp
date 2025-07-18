// IN THE NAME OF ALLAH
// Coded by Ahsanul Imam
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>order_set;
// find_by_order() - Returns an iterator to the k-th largest element(counting from zero)
// order_of_key() - The number of items in a set that are strictly smaller than our item
typedef long long int ll;
const int  MOD = 1000000007;
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define nl '\n';
#define bit(a) __builtin_popcountll(a)
#define w(x) while (x--)
#define test int t; cin>>t; for (int i = 1; i <= t; i++)
#define loop for (int i = 0; i < n; i++)
#define print(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define gcd(a, b) __gcd<long long int>(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define pi 2*acos(0.0)
#define pr pair<ll, ll>
#define Ahsanul (ios_base::sync_with_stdio(false), cin.tie(NULL))
vector<pr>knight_posible{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};//knight moves
vector<pr>posible{{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};//eight direction moves;
int power(int a,int b){int res=1;while (b){if (b&1){res=(res*1ll*a)%MOD;}a=(a*1ll*a)%MOD;b>>=1;}return res;}
ll inversemod(ll base) { return power(base,MOD-2); }
// const int N=1e6+10;
// vector<bool>prime(N,true);
// vector<int>lp(N);
void solve()
{
    ll n; cin>>n;
    vector<pr>v;
    map<ll,int>fre;
    ll tem=n;
    while(tem%2==0)
    {
        ++fre[2];
        tem/=2;
    }
    for(int i=3;i*i<=tem;i+=2)
    {
        while(tem%i==0 and tem)
        {
            fre[i]++;
            tem/=i;
        }
    }
    if(tem>2)
    {
        fre[tem]++;

    }
    for(auto &[x,y]:fre)
    {
        //cout<<x<<' '<<y<<nl;
        v.pb({y,x});
    }
    srt(v);
    // for(auto it:v)
    // {
    //     cout<<it.f<<" "<<it.s<<nl;
    // }
    int m=(int)v.size();
    vl pre(m);
    pre[m-1]=v[m-1].s;
    for(ll i=m-2;i>=0;i--)
    {
        pre[i]=(pre[i+1]*1ll*v[i].s);
    }
    //print(pre);
    ll bad=0;
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        ll gun=v[i].f;
        gun-=bad;
        ans+=(pre[i]*gun);
        bad+=gun;
    }
    cout<<ans<<nl;
}
int main()
{
    Ahsanul;
    // for(int i=1;i<=N;i++)lp[i]=i;
    // prime[0]=prime[1]=false;
    // for(int i=2;i*i<=N;i++)
    // {
    //     if(prime[i])
    //     {
    //         for(int j=i*i;j<=N;j+=i)
    //         {
    //             prime[j]=false;
    //             if(lp[j]==j)
    //                 lp[j]=i;
    //         }
    //     }
    // }
    test
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}