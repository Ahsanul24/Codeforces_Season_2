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
    string s;int x; cin>>s>>x;
    string mini="",houru="";
    houru+=s[0];houru+=s[1];mini+=s[3];mini+=s[4];
    int mint=stoi(mini),hr=stoi(houru);
    //cout<<mint<<' '<<hr<<nl;
    int joghr=(x/60),jogminit=x-(60*(x/60));
    //cout<<joghr<<' '<<jogminit<<nl;
    map<string,int>fre;
    string ori_mini=mini,ori_houru=houru;
    while(true)
    {
        string dem=houru;
        dem+=mini;
        string tem=dem;
        //cout<<dem<<nl;
        reverse(tem.begin(),tem.end());
        if(tem==dem)
        {
            fre[tem]++;
        }
        mint+=jogminit;
        if(mint>=60)
        {
            hr+=(mint/60);
            mint=mint-(60*(mint/60));
        }
        hr+=joghr;
        if(hr>=24)
        {
            hr=hr-24;
        }
        mini=to_string(mint);
        if((int) mini.size()==1)
        {
            mini="0"+mini;
        }
        houru=to_string(hr);
        if((int) houru.size()==1)
        {
            houru="0"+houru;
        }
        if(mini==ori_mini and houru==ori_houru)break;
        //cout<<houru<<' '<<mini<<nl;
        x+=mint;
        x+=(hr*60);
    }
    // for(auto &[x,y]:fre)
    // {
    //     cout<<x<<" "<<y<<nl;
    // }
    // cout<<nl;
    cout<<(int)fre.size()<<nl;
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