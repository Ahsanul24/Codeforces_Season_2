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
    int n,m; cin>>n>>m;
    map<string,int>fre;
    for(int i=1;i<=n;i++)
    {
        string x; cin>>x;
        fre[x]++;
    }
    string mid="";
    deque<string>ans;
    for(auto &[x,y]:fre)
    {
        if(y==0)continue;
        string curr=x;
        string tem=curr;
        reverse(tem.begin(),tem.end());
        string dem=tem;
        reverse(dem.begin(),dem.end());
        int mini=0;
        if(dem!=tem)
            mini=(fre[curr]+fre[tem]);
        else
            mini=min(fre[curr],fre[tem]);
        //cout<<tem<<' '<<dem<<' '<<curr<<nl;
        if(dem==tem)//already plaindrome
        {
            // cout<<mini<<nl;
            if(mini>=1 and (mini&1))
            {
                mid=curr;
                mini--;
            }
            for(int i=1;i<=mini/2;i++)
            {
                ans.push_front(curr);
                ans.push_back(curr);
                fre[curr]-=2;
            }

        }
        else if(fre[curr] and fre[tem])
        {
            //cout<<mini<<nl;
            if((mini&1))
            {
                mini--;
            }
            for(int i=1;i<=mini/2;i++)
            {
                ans.push_front(curr);
                ans.push_back(tem);
                fre[curr]--;
                fre[tem]--;
            }
        }
    }
    int sz=(int)ans.size();
    if(sz==0 and (int)mid.size()==0)
    {
        cout<<0<<nl;
        return;
    }
    ll tot=sz*m+((int)mid.size());
    cout<<tot<<nl;
    for(int i=1;i<=(sz/2);i++)
    {
        cout<<ans[i-1];
    }
    cout<<mid;
    for(int i=(sz/2)+1;i<=sz;i++)
    {
        cout<<ans[i-1];
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