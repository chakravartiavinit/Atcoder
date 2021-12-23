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
    int n, m;
    cin >> n >> m;
    bool flag = true;
    vector<int> vt(n, 0);
    int index = INT_MAX;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        index = min(index, a - 1);
        if (a - 1 == 0 && b == 0)
        {
            flag = false;
        }
        else
        {
            if (vt[a - 1] != 0)
            {
                if (vt[a - 1] != b)
                {
                    flag = false;
                }
            }
            else
            {
                vt[a - 1] = b;
            }
        }
    }
    if (flag == false)
    {
        cout << "-1\n";
    }
    else
    {
        string temp;
        for (int i = index; i < vt.size(); ++i)
        {
            temp.push_back(vt[i] + '0');
        }
        if (temp.size() == n)
        {
            cout << temp;
        }
        else if (temp.size() < n)
        {
            cout << "-1\n";
        }
        else
        {
            bool flag2 = true;
            int alpha = temp.size();
            for (int i = n - 1; i >= 0; i--)
            {
                if (alpha == n)
                {
                    break;
                }
                else
                {
                    if (temp[i] == 0)
                    {
                        alpha--;
                    }
                    else
                    {
                        flag2 = false;
                        break;
                    }
                }
            }
            if (flag2 == false)
            {
                cout << "-1\n";
            }
            else
            {
                for(int i=index;i<=alpha;++i)
                {
                    cout<<temp[i];
                }
            }
        }
    }
    debug(vt);
}
