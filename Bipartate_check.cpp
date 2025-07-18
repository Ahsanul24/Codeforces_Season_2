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
bool call(int st, vector<int> &color, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(st);
    color[st] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto it : adj[curr])
        {
            if (color[it] == -1)
            {
                color[it] = !color[curr];
                q.push(it);
            }
            else if (color[it] == color[curr])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &adj)
{
    // Code here
    vector<int> color((int)adj.size(), -1);
    for (int i = 0; i < (int)adj.size(); i++)
    {
        if (color[i] == -1)
        {
            if (!call(i, color, adj))
            {
                return false;
            }
        }
    }
    return true;
}
void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<int>>graph(n);

    for(int i=0;i<m;i++)
    {
        int e,v; cin>>e>>v;
        graph[e].push_back(v);
        graph[v].push_back(e);
    }
    if (isBipartite(graph))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
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