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
#define cnt_sese_sunno(x) __builtin_ctz(x)
#define cnt_age_sunno(x) __builtin_clz(x)
#define cnt_sese_ek(x) __builtin_ctz(~x)
#define cnt_age_ek(x) __builtin_clz(~x)
#define parity(x) __builtin_parity(x)
#define parityLL(x) __builtin_parityll(x)
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
const int MX = 1e6 + 10;
struct Query
{
    int L, R, indx;
};
int a[MX], freq[MX], ans[MX];
Query Q[MX];
int q, unq, block = 700,cnt=0;
bool cmp(Query a, Query b)
{
    if (a.L / block != b.L / block)
        return a.L < b.L;
    return a.R < b.R;
}
void Add(int pos,int k) 
{
    freq[a[pos]]++;
    if (freq[a[pos]] >= k)
    {
        if(freq[a[pos]]%k==0)
        {
            cnt++;
        }
    }
}
void Remove(int pos,int k) 
{
    if (freq[a[pos]] == k)
    {
        if(freq[a[pos]]%k==0)
        {
            cnt--;
        }
    }
    freq[a[pos]]--;
}
void AnswerQuery(int k)
{
    int cur_L = 0, cur_R = -1;
    for (int i = 0; i < q; i++)
    {
        int left = Q[i].L;
        int right = Q[i].R;
        while (cur_L > left)
            cur_L--, Add(cur_L,k);
        while (cur_R < right)
            cur_R++, Add(cur_R,k);
        while (cur_L < left)
            Remove(cur_L,k), cur_L++;
        while (cur_R > right)
            Remove(cur_R,k), cur_R--;
        ans[Q[i].indx] = cnt;
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<nl;
    }
}
int main()
{
    int n,k; cin>>n>>k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].L >> Q[i].R;
        Q[i].indx = i;
        Q[i].L--, Q[i].R--;
    }
    sort(Q, Q + q, cmp);
    AnswerQuery(k);
}

