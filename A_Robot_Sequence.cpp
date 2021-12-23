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
    int n;
    cin >> n;
    string alpha;
    cin >> alpha;
    int finalans = 0;
    for (int i = 0; i < alpha.length(); ++i)
    {
        int right = 0, left = 0, up = 0, down = 0;
        if (alpha[i] == 'R')
        {
            right++;
        }
        else if (alpha[i] == 'L')
        {
            left++;
        }
        else if (alpha[i] == 'U')
        {
            up++;
        }
        else if (alpha[i] == 'D')
        {
            down++;
        }
        for (int j = i + 1; j < alpha.length(); ++j)
        {
            if (alpha[j] == 'R')
            {
                right++;
            }
            else if (alpha[j] == 'L')
            {
                left++;
            }
            else if (alpha[j] == 'U')
            {
                up++;
            }
            else if (alpha[j] == 'D')
            {
                down++;
            }
            if (abs(right - left) == 0 && abs(up - down) == 0)
            {
                finalans++;
            }
        }
    }
    cout << finalans << "\n";
}
