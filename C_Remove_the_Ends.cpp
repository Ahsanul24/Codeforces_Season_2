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
// const int N=2e5+10;
// ll dp_sona[N];
// ll call(vl &v,int idx,ll sum,int sz,bool key)//dp expart be like tomar kache jeta dp_sona amar kache seta khelna
// {
//     if(idx==sz)
//     {
//         return 0;
//     }
//     if(dp_sona[idx]!=-1)return dp_sona[idx];
//     if(v[idx]<0)
//     {
//         if(key)
//         { 
//             //cout<<idx<<nl;
//             return dp_sona[idx] = max(call(v,idx+1,sum,sz,1),abs(v[idx])+call(v,idx+1,sum,sz,0));
//         }
//         else
//         {
//             //cout<<idx<<' '<<v[idx]<<nl;
//             return dp_sona[idx] = abs(v[idx])+call(v,idx+1,sum,sz,0);
//         }
//     }
//     else
//     {
//         if(key)
//         { 
//             //cout<<idx<<nl;
//             return dp_sona[idx]=max(v[idx]+call(v,idx+1,sum,sz,1),v[idx]+call(v,idx+1,sum,sz,0));
//             // return v[idx]+call(v,idx+1,sum,sz,1);
//         }
//         else
//         {
//             //cout<<idx<<nl;
//             return dp_sona[idx]=0+call(v,idx+1,sum,sz,0);
//         }
//     }
// }
// ll call_2(vl &v,int idx,ll sum)
// {
//     if(idx<0)
//     {
//         return 0;
//     }
//     if(dp_sona[idx]!=-1)return dp_sona[idx];
//     if(v[idx]<0)
//     {
//         return dp_sona[idx]=max(abs(v[idx])+call_2(v,idx-1,sum),call_2(v,idx-1,sum));
//     }
//     else
//     {
//         return dp_sona[idx]=max(v[idx]+call_2(v,-1,sum),call_2(v,idx-1,sum));
//     }
// }
void solve()
{
    int n; cin>>n;
    vi v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vl sum;
    ll tem_sum=0;
    for(int i=1;i<=n;)
    {
        if(v[i]>0)
        {
            while(v[i]>0 and i<=n)
            {
                tem_sum+=v[i];
                i++;
            }
            sum.pb(tem_sum);
            tem_sum=0;
        }
        else
        {
            while(v[i]<0 and i<=n)
            {
                tem_sum+=abs(v[i]);
                i++;
            }
            sum.pb(-tem_sum);
            tem_sum=0;
        }
    }
    // for(auto it:sum)cout<<it<<' ';cout<<nl;;
    int m=(int)sum.size();
    vl kocu_pos(m),kocu_neg(m);
    for(int i=0;i<m;i++)
    {
        if(i==0)
        {
            if(sum[i]>0)
            {
                kocu_pos[i]=sum[i];
            }
            continue;
        }
        if(sum[i]>0)
        { 
            kocu_pos[i]+=kocu_pos[i-1]+sum[i];
        }
        else
        {
            kocu_pos[i]+=kocu_pos[i-1];
        }
    }
    for(int i=0;i<m;i++)
    {
        if(i==0)
        {
            if(sum[i]<0)
            {
                kocu_neg[i]=-sum[i];
            }
            continue;
        }
        if(sum[i]<0)
        { 
            kocu_neg[i]+=kocu_neg[i-1]+(-sum[i]);
        }
        else
        {
            kocu_neg[i]+=kocu_neg[i-1];
        }
    }
    // for(auto it:kocu_pos)cout<<it<<' ';cout<<nl;
    // for(auto it:kocu_neg)cout<<it<<' ';cout<<nl;
    ll ans=INT_MIN;
    for(int i=0;i<m;i++)
    {
        ans=max(ans,max({(kocu_pos[i]+(kocu_neg[m-1]-kocu_neg[i])),kocu_neg[i],kocu_pos[i]}));
    }
    cout<<ans<<nl;
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