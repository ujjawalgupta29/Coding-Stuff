#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define ve(x) vector<x>
#define f(a,b,c) for(ll a=b;a<c;a++)
#define foto(x,v) for(auto x:v)
#define read(t) ll t; cin>>t;
#define reads(t) string t; cin>>t;
#define readarr(arr,n) ll arr[n]; f(i,0,n) cin>>arr[i];
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
const ll M = 1e9+7 , INF = 1e16;
ll powm(ll a, ll b , ll c = M) { ll res=1; while(b) { if(b&1) res=(res*a)%c; a=(a*a)%c; b>>=1; } return res;}
const ld PI = acosl(-1.0);
// #define pii(x , y) (pii){x,y}
unordered_map<ll,ld> thes;
#define ch(x) (isnt[flip(x).first*1e9+flip(x).second]==0 and isnt[x.first*1e9+x.second]==0)
#define  ch2(x) (abs(x.first)<=2e9 and abs(x.second)<=2e9)

pii poo(ll x, ll y)
{
    ll g = __gcd(abs(x),abs(y));
    assert(g);
    return pii(x/g,y/g);
}
pii poo(pii a)
{
    ll x = a.first , y = a.second;
    ll g = __gcd(abs(x),abs(y));
    assert(g);
    return pii(x/g,y/g);
}

ll find_Q(pii x)
{
    if(x.first>=0 and x.second>=0) return 1;
    if(x.first<0 and x.second>=0) return 2;
    if(x.first>=0 and x.second<0) return 4;
    if(x.first<0 and x.second<0) return 3;
    return INF;
}

bool comp(pii a , pii b)
{
    if(find_Q(a)!=find_Q(b)) return find_Q(a)<find_Q(b);
    ld r1 =  a.first*a.first + a.second*a.second;
    ld r2 =  b.first*b.first + b.second*b.second;
    if(find_Q(a)==1) return (a.second*a.second/r1) <(b.second*b.second/r2);
    if(find_Q(a)==2) return (a.first*a.first/r1) <(b.first*b.first/r2);
    if(find_Q(a)==3) return (a.second*a.second/r1) <(b.second*b.second/r2);
    if(find_Q(a)==4) return (a.first*a.first/r1) <(b.first*b.first/r2);
    return 1;
}

// bool operator<( const pii& a , const pii& b )
// {
//      return comp(a , b);
// }

pii flip(pii x)
{
    return pii(x.first*(-1) , x.second*(-1));
}


bool gr(pii a , pii b)
{
    ll A = find_Q(a);
    ll B = find_Q(b);
    if(abs(A-B)>2) return 1;
    if(abs(A-B)<2) return 0;
    if(A == 1)
    {
        if(comp(flip(a), b)) return 1;
        return 0 ;
    }
    if(A == 2)
    {
        if(comp(flip(a), b)) return 1;
        return 0 ;
    }
    if(A == 3)
    {
        if(comp(flip(a), b)) return 0;
        return 1 ;
    }
    if(A == 4)
    {
        if(comp(flip(a), b)) return 0;
        return 1 ;
    }
}



pii mid(pii x , pii y)
{
    ll X = x.first+y.first , Y= x.second+y.second;
    // assert(x.second and x.first);
    if(X==0 and Y==0 )
    {
        X = -1*x.second;
        Y=  x.first;
    }
    // assert(X and Y);
    return pii(X,Y);
}

// 														MAIN
int32_t main()
{ 
    FASTIO 
    read(t) while(t--)
    {
        read(n)
        thes.clear();
        ve(pii) temp;
        f(i,0,n) 
        {
            read(x) read(y) temp.push_back({x,y});
        }
        temp.push_back(temp[0]);
        ve(pii) prs,orig;
        f(i,0,n)
        {
            prs.push_back(poo(temp[i+1].first-temp[i].first , temp[i+1].second-temp[i].second));
            orig.push_back(prs[i]);
        }
        unordered_map<ll,bool> is_mid ,isnt;
        // sort(all(prs),comp);
        
        f(i,0,n) isnt[orig[i].first*1e9+orig[i].second] = 1;
        f(i,0,n) isnt[flip(orig[i]).first*1e9+flip(orig[i]).second] = 1;
        
        ll x = prs.size();
        f(i,0,x) prs.push_back(flip(prs[i]));
        set<pii> s;
        f(i,0,prs.size()) s.insert(prs[i]);
        prs.clear();
        for(auto x:s) prs.push_back(x);
        sort(all(prs) , comp);
        x = prs.size();
        f(i,0,x) 
        {
            auto t = mid(prs[i],prs[(i+1)%x]);
            t = poo(t);
            s.insert(t);
            s.insert(flip(t));
        }
        prs.clear();
        for(auto x:s) prs.push_back(x);
        sort(all(prs) , comp);
        ll rot = 0 , ct = 0 , sz = s.size() + 5;
        ll f[sz] = {0};
        // cout<<endl;
        // f(i,0,prs.size()) cout<<prs[i].first<<" "<<prs[i].second<<endl;
        // cout<<endl;
        unordered_map<ll,ll> mp;
        for(auto x: prs) mp[x.first*1e9+x.second]= ct++;
        orig.push_back(orig[0]);
        f(i,0,n)
        {
            auto cur = mp[orig[i].first*1e9+orig[i].second] , next = mp[orig[i+1].first*1e9+orig[i+1].second];
            if(cur == next) continue;
            if(comp(orig[i],orig[i+1]))
            {
                if(!gr(orig[i],orig[i+1])) f[cur]++ , f[next+1]--;
                else
                {
                    rot++;
                    f[cur+1]-- , f[next]++;
                }
            }
            if(!comp(orig[i],orig[i+1]))
            {
                if(!gr(orig[i],orig[i+1])) f[next]++ , f[cur+1]--;
                else
                {
                    rot++;
                    f[next+1]-- , f[cur]++;
                }
            }
        }
        f(i,1,sz) f[i] += f[i-1];
        f(i,0,sz) f[i] += rot;
        assert(f[0]>=0);
        // f(i,0,sz) cout<<f[i]<<" ";
        // cout<<endl;
        f(i,0,prs.size()) if(ch(prs[i]) and ch2(prs[i])) if(f[mp[prs[i].first*1e9+prs[i].second]]+f[mp[flip(prs[i]).first*1e9+flip(prs[i]).second]] ==2) 
        {
            // if(isnt[prs[i].second*(-1) * 1e9 + prs[i].first] ==1) continue;
            cout<<prs[i].second*(-1)<<" "<<prs[i].first<<"\n"; goto meow;
        }
        cout<<0<<" "<<0<<"\n";
        meow:;
    }
}