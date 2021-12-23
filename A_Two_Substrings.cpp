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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a;
    string alpha;
    cin >> alpha;
    bool flag = false;
    debug(flag);
    for (int i = 0; i < alpha.length(); ++i)
    {
        if (alpha[i] == 'A' && alpha[i + 1] == 'B')
        {
            a.push_back(i);
            a.push_back(i + 1);
            break;
        }
    }
    if (a.size() == 2)
    {
        for (int i = a[1] + 1; i < alpha.length(); ++i)
        {
            if (alpha[i] == 'B' && alpha[i + 1] == 'A')
            {
                flag = true;
                break;
            }
        }
    }
    vector<int> b;
    for (int i = 0; i < alpha.length(); ++i)
    {
        if (alpha[i] == 'B' && alpha[i + 1] == 'A')
        {
            b.push_back(i);
            b.push_back(i + 1);
            break;
        }
    }
    debug(b);
    if (b.size() == 2)
    {
        for (int i = b[1] + 1; i < alpha.length(); ++i)
        {
            if (alpha[i] == 'A' && alpha[i + 1] == 'B')
            {
                flag = true;
                break;
            }
        }
    }
    debug(flag);
    if (flag == true)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
