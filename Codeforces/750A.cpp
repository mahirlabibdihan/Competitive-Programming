/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|

*/

#include<bits/stdc++.h>
using namespace std;
#define ed end()
#define fi first
#define se second
#define MAX 200001
#define INF 1e18
#define bg begin()
#define si set<int>
#define sll set<ll>
#define ll long long
#define pb push_back
#define pf push_front
#define pi 3.14159265
#define spii set<pii>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define MOD 1000000007
#define p_b pop_back()
#define p_f pop_front()
#define u_b upper_bound
#define l_b lower_bound
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mii map<int,int>
#define mii map<int,int>
#define mci map<char,int>
#define pii pair<int,int>
#define mci map<char,int>
#define vd vector<double>
#define u_s unordered_set
#define u_m unordered_map
#define b_s binary_search
#define max_of max_element
#define vtiii vector<tiii>
#define gcd(a,b) __gcd(a,b)
#define pstv(x) if(x<0) x=0
#define ngtv(x) if(x>0) x=0
#define read(x) for(auto &i:x)
#define visit(x) for(auto i:x)
#define usi unordered_set<int>
#define ull unsigned long long
#define print(a) cout<<a<<"\n"
#define printn(a) cout<<a<<endl
#define pqi priority_queue<int>
#define tiii tuple<int,int,int>
#define ptr(x) x.begin(),x.end()
#define mx(a,b,c) max(a,max(b,c))
#define mn(a,b,c) min(a,min(b,c))
#define rptr(x) x.rbegin(),x.rend()
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define _for(i,a,n) for(i=a;i<n;i++)
#define for_(i,a,n) for(i=a;i>n;i--)
#define maxof(x)  max_element(ptr(x))
#define v_in(x) for(auto &i:x) cin>>x[i]
#define _pow(a,b,c) ull c=1;for(;b--;c*=a)
#define srt(x) sort(x.begin(),x.begin()+n)
#define sum(x,s) ll s=0; for(auto i:x) s+=i
#define adjdif(x) for_(i,n-1,0) x[i]-=x[i-1]
#define v_in2(x,y) _for(i,0,n) cin>>x[i]>>y[i]
#define vp_in(x) for(auto &i:x) cin>>x.fi>>x.se
#define ub(x,a) upper_bound(ptr(x),a)-x.begin()
#define lb(x,a) lower_bound(ptr(x),a)-x.begin()
#define rotate_l(x,a)  rotate(x.bg,x.bg+a,y.ed)
#define bs(x,a) binary_search(ptr(x),a)-x.begin()
#define pre_sum(x) _for(i,1,x.size()) x[i]+=x[i-1]
#define rotate_r(x,a)  rotate(x.bg,x.bg+x.sz-a,y.ed)
#define FOR(i,x) for(auto i=x.begin();i!=x.end();i++)
#define out(x) for(auto i:x)  cout<<i<<" "; cout<<"\n"
#define outn(x) for(auto i:x) cout<<i<<" "; cout<<endl
#define ____ ios::sync_with_stdio(0);  cin.tie(nullptr);
#define s_in(x) for(i=0,int a;i<n,cin>>a;i++) x.insert(a)
#define m_in(x) for(i=0,int a,b;i<n,cin>>a>>b;i++) x[a]=b
ll t,n,i,j,k,a,b,c
;
void dihan()
{
	 cin>>n>>t; t=240-t;  vi x(n,5);
	 for(;i<n;)x[i++]*=i; prefix_sum(x);
     print(ub(x,t));
}

int main(){____ dihan();}
