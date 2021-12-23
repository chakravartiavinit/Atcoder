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
    int arr[3][3];
    bool flag = false;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> arr[i][j];
        }
    }
    unordered_set<int> alpha;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        alpha.insert(temp);
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (alpha.find(arr[i][j]) != alpha.end())
            {
                arr[i][j] = -1;
            }
        }
    }
    if (arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1)
    {
        flag = true;
    }
    if (arr[2][0] == -1 && arr[1][1] == -1 && arr[0][2] == -1)
    {
        flag = true;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i][0] == -1 && arr[i][1] == -1 && arr[i][2] == -1)
        {
            flag = true;
        }
        if (arr[0][i] == -1 && arr[1][i] == -1 && arr[2][i] == -1)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
