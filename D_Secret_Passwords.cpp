#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define PI 3.141592653589793238462

/*########################################### DEBUG ###############################################################################################*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t)
{
    cerr << t;
}
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

/*###############################################################################################################################################*/
vector<int> graph[2000005];
vector<bool> visited(2000005, false);
void dfs(vector<int> vt, int n)
{
    visited[n] = true;
    for (auto x : vt)
    {
        if (visited[x] == false)
        {
            dfs(graph[x], x);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            string alpha;
            cin >> alpha;
            if (alpha.length() == 1)
            {
                graph[alpha[0] - 'a'].push_back(alpha[0] - 'a');
            }
            for (int i = 0; i < alpha.length() - 1; ++i)
            {
                graph[alpha[i] - 'a'].push_back(alpha[i + 1] - 'a');
                graph[alpha[i + 1] - 'a'].push_back(alpha[i] - 'a');
            }
        }
        int count = 0;
        for (int i = 0; i <= 26; ++i)
        {
            if (graph[i].empty() == false && visited[i] == false)
            {
                dfs(graph[i], i);
                count++;
            }
        }
        cout << count << "\n";
    }
}
