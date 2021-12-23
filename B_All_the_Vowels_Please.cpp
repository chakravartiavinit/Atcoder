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
    int k;
    cin >> k;
    vector<int> factors;
    for (int i = 3; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            if (k / i == i)
            {
                factors.push_back(i);
            }
            else
            {
                factors.push_back(k / i);
                factors.push_back(i);
            }
        }
    }
    bool flag = false;
    int n = 0, m = 0;
    for (int i = 0; i < factors.size(); ++i)
    {
        if (factors[i] >= 5 && k / factors[i] >= 5)
        {
            m = factors[i];
            n = k / factors[i];
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "-1\n";
    }
    else
    {
        vector<char> vt = {'a', 'e', 'i', 'o', 'u'};
        string ans;
        for (int i = 0; i < m; ++i)
        {
            for (int i = 0; i < n; ++i)
            {
                ans.push_back(vt[i % 5]);
            }
        }
        cout << ans << "\n";
    }
}
