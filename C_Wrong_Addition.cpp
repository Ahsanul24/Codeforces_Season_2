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
#define S second
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
    string a,s; cin>>a>>s;
    string b="";
    int n=s.size(),m=a.size();
    if(n!=m)
    {
        while((int) a.size()!=n)
        {
            a="0"+a;
        }
    }
    int j=n-1,i;
    for(i=n-1;i>=0;i--)
    {
        if((i-1)>=0)
        {
            string tem="";
            if(s[i-1]!='0')
                tem+=s[i-1];
            tem+=s[i];
            //cout<<tem<<' '<<i<<' '<<a[j]<<nl;
            int dem=stoi(tem);
            int a_dem=a[j]-'0';
            if(dem-a_dem>=10)
            {
                int curr=s[i]-'0';
                if(curr<a_dem)
                {
                    cout<<-1<<nl;
                    return;
                }
                else
                {
                    //cout<<curr-a_dem<<nl;
                    b += to_string(curr - a_dem);
                }
            }
            else if(dem-a_dem>=0)
            {
                b += to_string(dem - a_dem);
                if(s[i-1]!='0')
                    i--;
            }
            else
            {
                cout<<-1<<nl;
                return;
            }
        }
        else
        {
            // cout<<a[i]<<' '<<i<<' '<<j<<nl;
            int a_dem = a[j] - '0';
            int curr = s[i] - '0';
            if (curr < a_dem)
            {
                cout << -1 << nl;
                return;
            }
            else
            {
                b += to_string(curr - a_dem);
            }
        }
        j--;
    }
    for(int k=j;k>=0;k--)
    {
        if(a[k]>'0')
        {
            cout<<-1<<nl;
            return;
        }
    }
    reverse(b.begin(),b.end());
    int idx=-1;
    for(int i=0;i<(int)b.size();i++)
    {
        if(b[i]>'0')
        {
            idx=i;
            break;
        }
    }
    for(int i=idx;i<(int)b.size();i++)
    {
        cout<<b[i];
    }
    cout<<nl;
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