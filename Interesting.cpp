#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
#define MOD 1000000007
#define PI 3.141592653589793238462
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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
const long long N = 4 * 1000000 + 4;
bool prime[N + 1];
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
vector<long long> trial_division2(long long n)
{
    vector<long long> factorization;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                factorization.push_back(i);
            }
            else
            {
                factorization.push_back(i);
                factorization.push_back(n / i);
            }
        }
    }
    return factorization;
}
vector<long long> value(1e6+5);
void Sieve(long long a)
{
    for (int m = 1; m <= a; ++m)
    {
        if (prime[4 * m + 1] == true)
        {
            value[m] = 6 * m;
        }
        else
        {
            long long number = 4 * m + 1;
            vector<long long> factors = trial_division2(number);
            long long ans = 0;
            long long count2 = 0;
            // debug(factors);
            // set<int>::reverse_iterator rit;
            // for (auto it = factors.rbegin(); it != factors.rend(); ++it)
            // {
            //     long long count = 0;
            //     for (int j = *it; j <= 2 * K; j += *it)
            //     {
            //         if (vt[j] == true)
            //         {
            //             count++;
            //             count2++;
            //             vt[j] = false;
            //         }
            //     }
            //     debug(count);
            //     ans = ans + count * (*it);
            // }
            map<long long, int> mp;
            for (int i = 0; i < factors.size(); ++i)
            {
                long long temp1 = (2 * m) / factors[i];
                mp[factors[i]] = temp1;
            }
            sort(factors.begin(), factors.end(), greater<int>());
            // for (auto x : mp)
            // {
            //     cout << x.first << " " << x.second << "\n";
            // }
            // for (auto x : factors)
            // {
            //     cout << x << " ";
            // }
            long long finalans = 0, counter = 0;
            for (int i = 0; i < factors.size(); ++i)
            {
                for (int j = i + 1; j < factors.size(); ++j)
                {
                    if (factors[i] % factors[j] == 0)
                    {
                        mp[factors[j]] = mp[factors[j]] - mp[factors[i]];
                    }
                }
            }
            debug(mp);
            for (auto x : mp)
            {
                finalans = finalans + (x.first * x.second);
                counter += x.second;
            }
            // cout << finalans << "\n";
            long long exd = finalans + 4 * m + (2 * m - counter);
            value[m] = exd;
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
    // SieveOfEratosthenes(N);
    Sieve(1e6);
    long long T;
    cin >> T;
    while (T--)
    {
        long long K;
        cin >> K;
        cout << value[K];
    }
}
// for (auto x : prime)
// {
//     cout << x << " ";
// }
