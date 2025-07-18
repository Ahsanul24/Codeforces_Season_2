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
    int n; cin>>n;
    vl v(n+3);
    for(int i=1;i<=n+2;i++)
    {
        cin>>v[i];
    }
    srt(v);
    ll sum=v[n+2];
    ll num=-1,sum_num=-1,arek=-1,sum_arek=-1;
    vl pre(n+3);
    for(int i=1;i<=n+2;i++)
    {
        pre[i]=pre[i-1]+v[i];
    }
    ll baki=v[n+1];
    for(int i=1;i<=n+2;i++)
    {
        if(pre[n+2]-sum-v[i]==sum and i<n+2)
        {
            num=v[i];
            sum_num=sum;
            bool check_a=false,check_b=false;
            for(int i=1;i<=n+2;i++)
            {
                if(!check_a and v[i]==num)
                {
                    check_a=true;
                    continue;
                }
                else if(!check_b and v[i]==sum)
                {
                    check_b=true;
                    continue;
                }
                cout<<v[i]<<' ';
            }
            cout<<nl;
            return;
        }
        else if(pre[n+2]-baki-v[i]==baki and i!=n+1)
        {
            arek=v[i];
            sum_arek=baki;
            int cnt=0;
            bool check_a=false,check_b=false;
            for(int i=1;i<=n+2;i++)
            {
                if(!check_a and v[i]==arek)
                {
                    check_a=true;
                    continue;
                }
                else if(!check_b and v[i]==baki)
                {
                    check_b=true;
                    continue;
                }
                cout<<v[i]<<' ';
            }
            cout<<nl;
            return;
        }
    }
    cout<<-1<<nl;
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