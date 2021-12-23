/*  
    Are you Pretest 2 ??
    Because I can't figure out what's wrong with you!

    Author - Coder_ravan
    Rating - Noob(newbie)
    
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include <utility>
#define int unsigned long long int
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define mp make_pair
#define vin(x,v) for(auto &x:v)cin>>x;
#define vout(x,v)for(auto x:v)cout<<x<<" ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i=j ; i<k ; i+=1)
#define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;


/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
#ifndef ONLINE_JUDGE
#define deb(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define deb(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
/*-----------------------------------D-E-B-U-G-----------------------------------------------*/

unordered_map<int, vector<int>> graph;
unordered_map<int, bool> visited;
unordered_map<int,int> rank;

void dfs(int n){
    visited[n]=true;
    for(auto x:graph[n]){
        if(!visited[x])dfs(x);
    }
    cout<<n<<" ";
}



void solve(){
    int n;cin>>n;
    vi v(n);
    vin(x,v);
    sort(v.begin(),v.end());
    for(auto x:v){
        if(binary_search(v.begin(),v.end(),x*2)){
            graph[x*2].pb(x);
        }
        if(binary_search(v.begin(),v.end(),x*3))graph[x].pb(x*3);
    }
    for(auto x:graph){
        if(x.second.size()==1 && !visited[x.first])dfs(x.first);
    }
}

signed main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); 
 //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  //cin>>t;
  deb(t);
  while(t--){
   solve();
  cout<<endl;
  }
}