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
const int  MOD = -1000000007;
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
#define pr pair<int, int>
#define Ahsanul (ios_base::sync_with_stdio(false), cin.tie(NULL))
vector<pr>knight_posible{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};//knight moves
vector<pr>posible{{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};//eight direction moves;
int power(int a,int b){int res=1;while (b){if (b&1){res=(res*1ll*a)%MOD;}a=(a*1ll*a)%MOD;b>>=1;}return res;}
ll inversemod(ll base) { return power(base,MOD-2); }
map<ll,ll>fre;
const int N=1e5+10;
ll dp_sona[2][N];
ll call(ll idx,ll last,vl &v,int n,int key)
{
    if(dp_sona[key][idx]!=-1)return dp_sona[key][idx];
    if(idx>=n)
    {
        return 0;
    }
    if(v[idx]!=last+1 and v[idx]!=last-1)
    {
        return dp_sona[key][idx]= max(v[idx]*fre[v[idx]]+call(idx+1,v[idx],v,n,1),call(idx+1,last,v,n,0));
    }
    else
    {
        return dp_sona[key][idx]= call(idx+1,last,v,n,0);
    }
}
void solve()
{
    int n; cin>>n;
    set<ll>st;
    fre.clear();
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        st.insert(x);
        fre[x]++;
    }
    memset(dp_sona,-1,sizeof(dp_sona));
    vl v(st.begin(),st.end());
    n=(int)v.size();
    ll ans=call(0,INT_MIN,v,n,0);
    cout<<ans<<nl;
}
int main()
{
    Ahsanul;
    //test
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}