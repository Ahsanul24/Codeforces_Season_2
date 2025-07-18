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
const int N=9999991;
vector<bool>prime(N,true);
vector<int>all_prime;
void solve()
{
    int n; cin>>n;
    vl v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    srt(v);
    ll coin=0;
    int j=n,k=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=j and v[i]<all_prime[k])
        {
            if(v[i]<all_prime[k])
            {
                //cout<<i<<" "<<j<<' '<<"HI"<<nl;
                ans++;
                continue;
            }
            continue;
        }
        if(v[i]<all_prime[k])
        {
            ll lage=all_prime[k]-v[i];
            if(lage<=coin)
            {
                v[i]=all_prime[k];
                k++;
            }
            else if((v[j]+coin)-lage>=2 and j>i)
            {
                v[i]=all_prime[k];
                lage-=coin;
                v[j]-=lage;
                coin=0;
                k++;
            }
            else
            {
                 //cout<<i<<" "<<v[j]<<' '<<j<<nl;
                // coin+=(v[j]-2);
                // j--;
                // if(lage<=coin)
                // {
                //     v[i]=all_prime[k];
                //     k++;
                // }
                // else if((v[j]+coin)-lage>=2 and j>i)
                // {
                //     v[i]=all_prime[k];
                //     lage-=coin;
                //     v[j]-=lage;
                //     coin=0;
                //     k++;
                // }
                // cout<<"ager coin"<<coin<<nl;
                // cout<<lage<<" "<<coin<<' '<<i<<" "<<j<<" "<<all_prime[k]<<nl;
                while(coin<lage and j>=i and (v[j]-2)>=2)
                {
                    if(lage-coin>v[j]-2)
                    {
                        coin+=v[j]-2;
                        v[j]=2;
                        j--;
                    }
                    else
                    {
                        ll tem=coin;
                        ll nibo=lage-coin;
                        coin+=(lage-coin);
                        v[i]-=nibo;
                    }
                }
                if(coin>=lage)
                {
                    //cout<<"hello at"<<' '<<j<<nl;
                    v[i]=all_prime[k];
                    k++;
                    coin-=lage;
                }
                else
                {
                    ans++;
                }
            }
        }
        else
        {
            coin+=(v[i]-all_prime[k]);
            v[i]=all_prime[k];
            k++;
        }
    }
    // cout<<coin<<nl;
    print(v);
    cout<<ans<<nl;
}
int main()
{
    Ahsanul;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=N;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(prime[i])
        {
            all_prime.pb(i);
        }
    }
    test
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}