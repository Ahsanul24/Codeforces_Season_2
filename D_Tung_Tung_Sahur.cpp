// IN THE NAME OF ALLAH
// Coded by Ahsanul Imam
#include<bits/stdc++.h>
using namespace std;
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
    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();
    queue<pair<ll,char>>q,qq;
    char last;
    ll cnt=0;
    if(a[0]=='L')
    {
        last='L';
    }
    else
    {
        last='R';
    }
    for(ll i=0;i<n;i++)
    {
        if(i==n-1)
        {
            //cout<<a[i]<<nl;
            if(last!=a[i])
            {
                q.push({cnt,a[i-1]});
                q.push({1,a[i]});
            }
            else
            {
                q.push({cnt+1,a[i]});
            }
            break;
        }
        if((last!=a[i]))
        {
            //cout << a[i-1] << ' ' << i << ' '<<cnt<<nl;

            if(last=='L')q.push({cnt,'L'});
            else q.push({cnt,'R'});
            cnt=1;
            last=a[i];
        }
        else
        {
            cnt++;
        }
    }
    // cout<<nl;
    // while(!q.empty())
    // {
    //     cout<<q.front().f<<" "<<q.front().s<<nl;
    //     q.pop();
    // }
    cnt=0;
    if(b[0]=='L')last='L';
    else last='R';
    for(ll i=0;i<m;i++)
    {
        if(i==m-1)
        {
            //cout<<a[i]<<nl;
            if(last!=b[i])
            {
                qq.push({cnt,b[i-1]});
                qq.push({1,b[i]});
            }
            else
            {
                qq.push({cnt+1,b[i]});
            }
            break;
        }
        if((last!=b[i]))
        {
            //cout << a[i-1] << ' ' << i << ' '<<cnt<<nl;

            if(last=='L')qq.push({cnt,'L'});
            else qq.push({cnt,'R'});
            cnt=1;
            last=b[i];
        }
        else
        {
            cnt++;
        }
    }
    if((ll)q.size()!=(ll)qq.size())
    {
        cout<<"NO"<<nl;
        return;
    }
    while(!qq.empty())
    {
        ll tem=qq.front().f,dem=q.front().f;
        char tem_c=qq.front().s,dem_c=q.front().s;
        //cout<<tem<<" "<<tem_c<<' '<<dem<<' '<<dem_c<<nl;
        qq.pop();
        q.pop();
        if(tem_c!=dem_c)
        {
            cout<<"NO"<<nl;
            return;
        }
        else if((tem>dem*2) or (tem<dem))
        {
            cout<<"NO"<<nl;
            return;
        }
    }
    cout<<"YES"<<nl;
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