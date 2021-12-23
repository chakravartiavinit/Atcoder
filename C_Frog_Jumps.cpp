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
vector<int> visited(2000005, false);
void dfs(int n)
{
    visited[n] = true;
    // cout << n << " ";
    for (auto x : graph[n])
    {
        if (visited[x] == false)
        {
            dfs(x);
            // cout << "\n";
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
    int t;
    cin >> t;
    while (t--)
    {
        int count = 0;
        string alpha;
        cin >> alpha;
        if (alpha.length() == 1)
        {
            if (alpha == "L")
            {
                cout << 2 << "\n";
            }
            else if (alpha == "R")
            {
                cout << 1 << "\n";
            }
        }
        else
        {
            for (int i = 0; i + 1 < alpha.length(); ++i)
            {
                if ((alpha[i] == 'R' && alpha[i + 1] == 'R'))
                {
                    graph[i].push_back(i + 1);
                    graph[i + 1].push_back(i);
                }
            }
            for (int i = 1; i < alpha.length(); ++i)
            {
                if ((alpha[i] == 'L') && (alpha[i - 1] == 'R'))
                {
                    graph[i].push_back(i + 1);
                    graph[i + 1].push_back(i);
                }
            }
            for (int i = 0; i < alpha.length(); ++i)
            {
                if (visited[i] == false)
                {
                    dfs(i);
                    count++;
                }
            }
            if (count == 1)
            {
                cout << count << "\n";
            }
            else
            {
                cout << count - 1 << "\n";
            }
        }
    }
}