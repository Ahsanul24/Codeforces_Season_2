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
bool cmp(pr a,pr b)
{
    if(a.f==b.f)
    {
        return a.s<b.s;
    }
    return a.f<b.f;
}
void solve()
{
    int n,h,m; cin>>n>>h>>m;
    vector<pr>v(n);
        int check=false;

    for(int i=0;i<n;i++)
    {
        cin>>v[i].f>>v[i].s;
        if(v[i].f==h and v[i].s==m)
        {
            check=true;
        }
    }
    if(check)
    {
        cout<<"0 0"<<nl;
        return;
    }
    int target_h=24,target_m=61;
    sort(v.begin(),v.end(),cmp);
    pr p={h,m};
    if((v[n-1].f==h and v[n-1].s>m) or v[n-1].f>h)
    {
        int idx=lower_bound(v.begin(),v.end(),p)-v.begin();
        //cout<<v[idx].f<<' '<<v[idx].s<<nl;
        int hour=0,minit=0;
        if(v[idx].f>h)
        { 
            minit+=(60-m)+v[idx].s;
        }
        else
        {
            minit+=(v[idx].s-m);
        }
        if(v[idx].f>h)
        { 
            minit+=(v[idx].f-h-1)*60;
        }
        //cout<<minit<<nl;
        hour=(minit/60);
        minit%=60;
 
        cout<<hour<<' '<<minit<<nl;
        return;
    }
    target_h=v[0].f,target_m=v[0].s;
    int hour=0,minit=0;
    minit+=(60-m)+target_m;
    minit+=(24-h-1)*60;
    minit+=(target_h-0)*60;
    //cout<<minit<<nl;
    hour=(minit/60);
    minit%=60;
    cout<<hour<<' '<<minit<<nl;
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