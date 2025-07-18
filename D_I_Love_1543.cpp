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
#define pr pair<int, int>
#define Ahsanul (ios_base::sync_with_stdio(false), cin.tie(NULL))
vector<pr>knight_posible{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};//knight moves
vector<pr>posible{{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};//eight direction moves;
int power(int a,int b){int res=1;while (b){if (b&1){res=(res*1ll*a)%MOD;}a=(a*1ll*a)%MOD;b>>=1;}return res;}
ll inversemod(ll base) { return power(base,MOD-2); }
string call(vector<vector<char>>&v,int n,int m,int x)
{
    string tem="";
    for(int i=x;i<=m-x+1;i++)
    {
        tem+=v[x][i];
    }
    for(int i=x+1;i<=n-x+1;i++)
    {
        tem+=v[i][m-x+1];
    }
    for(int i=m-x;i>=x;i--)
    {
        tem+=v[n-x+1][i];
    }
    for(int i=n-x;i>x;i--)
    {
        tem+=v[i][x];
    }
    // for(int i=x+1;i<=m-x+1 and xy!="1543";i++)
    // {
    //     tem+=v[x][i];
    // }
    // for(int i=x+1;i<=n-x+1 and yz!="1543";i++)
    // {
    //     tem+=v[i][m-x+1];
    // }
    // for(int i=m-x;i>=x and ab!="1543";i--)
    // {
    //     tem+=v[n-x+1][i];
    // }
    // for(int i=n-x;i>=x and bc!="1543";i--)
    // {
    //     tem+=v[i][x];
    // }
    return tem;
}
int koto(string x,int len)
{
    int cntt=0;
    for(int i=0;i<len;i++)
    {
        if(x[i]=='1' and x[(i+1)%len]=='5' and x[(i+2)%len]=='4' and x[(i+3)%len]=='3')
        {
            cntt++;
        }
    }
    return cntt;
}
void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<char>>v(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=min(n,m)/2;i++)
    {
        string tem=call(v,n,m,i);
        //cout<<tem<<nl;
        int sz=(int)tem.size();
        cnt+=koto(tem,sz);
    }
    cout<<cnt<<nl;
}
int main()
{
    Ahsanul;
    test
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}