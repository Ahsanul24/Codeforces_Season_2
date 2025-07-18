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
void solve()
{
    ll n,x; cin>>n>>x;
    if (n == 1 and x > 0)
    {
        cout << x << nl;
        return;
    }
    else if(x==0 and n>1)
    {
        if(n%2==0)
        {
            cout<<n<<nl;
            return;
        }
        else
        {
            cout<<(n-2)+5<<nl;
            return;
        }
    }
    if(x==0 and n==1)
    {
        cout<<-1<<nl;
        return;
    }
    vi v(34,0);
    int ff=-1,ss=-1;
    for(ll i=0;i<=32;i++)
    {
        if(x&(1LL<<i))
        {
            v[i]++;
        }
    }
    //cout<<ff<<' '<<ss<<nl;
    deque<ll> tem;
    for(ll i=0;i<=32;i++)
    {
        if(v[i])
        {
            tem.pb(1LL<<i);
        }
    }
    int bite = bit(x);
    if (bite >= n)
    {
        ll barti = bite - n;
        ll sum=0;
        while(barti)
        {
            sum+=tem.front();
            tem.pop_front();
            barti--;
        }
        tem.pb(sum);
        ll ans=accumulate(tem.begin(),tem.end(),0LL);
        cout<<ans<<nl;
        return;
    }
    ll barti=n-(int)tem.size();
    ll tot=accumulate(tem.begin(),tem.end(),0LL);
    //cout<<barti<<' '<<tot<<nl;
    //print(tem);
    if(barti%2==0)
    {
        tot+=barti;
        cout<<tot<<nl;
        return;
    }
    else
    {
        if(((int) tem.size()>1))
        { 
            ll dem=tem.front();
            tem.pop_front();
            dem+=tem.front();
            tem.pop_front();
            tem.pb(dem);
            //print(tem);
            ll ans=accumulate(tem.begin(),tem.end(),0LL);
            ans+=barti+1;
            cout<<ans<<nl;
            return;
        }
        else
        {
            if(x==1)
            {
                cout<<5+(n-2)<<nl;
                return;
            }
            else
            {
                cout<<(x+2)+(n-2)<<nl;
                return;
            }
        }
    }
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