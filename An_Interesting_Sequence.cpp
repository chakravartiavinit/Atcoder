#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
long long binpower(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool probablyPrimeFermat(int n, int iter = 5)
{
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
// vector<long long> trial_division1(long long n)
// {
//     vector<long long> factorization;
//     for (long long d = 2; d * d <= n; d++)
//     {
//         while (n % d == 0)
//         {
//             factorization.push_back(d);
//             n /= d;
//         }
//     }
//     if (n > 1)
//         factorization.push_back(n);
//     return factorization;
// }
// #define MAXSIEVE 1000000 // All prime numbers up to this
// #define MAXSIEVEHALF (MAXSIEVE / 2)
// #define MAXSQRT 500 // sqrt(MAXSIEVE)/2
// char a[MAXSIEVE / 16 + 2];
// #define isprime(n) (a[(n) >> 4] & (1 << (((n) >> 1) & 7))) // Works when n is odd

// //have to check for even numbers
// void sieve()
// {
//     int i, j;
//     memset(a, 255, sizeof(a));
//     a[0] = 0xFE;
//     for (i = 1; i < MAXSQRT; i++)
//         if (a[i >> 3] & (1 << (i & 7)))
//             for (j = i + i + i + 1; j < MAXSIEVEHALF; j += i + i + 1)
//                 a[j >> 3] &= ~(1 << (j & 7));
// }
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("error.txt", "w", stderr);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     sieve();
//     long long T;
//     cin >> T;
//     while (T--)
//     {
//         long long K;
//         cin >> K;
//         if (isprime(4 * K + 1) == true || a[4 * K + 1] == true)
//         {
//             cout << 6 * (1LL) * K << "\n";
//         }
//             else
//             {
//                 vector<long long> factors;
//                 long long temp1 = 4 * K + 1;
//                 factors = trial_division1(temp1);
//                 sort(factors.begin(), factors.end(), greater<int>());
//                 debug(factors);
//                 map<long long, int> mp;
//                 for (int i = 1; i <= 2 * K; ++i)
//                 {
//                     long long number = K + i * i;
//                     long long number2 = K + (i + 1) * (i + 1);
//                     for (int j = 0; j < factors.size(); ++j)
//                     {
//                         if (number % factors[j] == 0 && number2 % factors[j] == 0)
//                         {
//                             mp[factors[j]]++;
//                             break;
//                         }
//                     }
//                 }
//                 long long ans = 0, count = 0;
//                 for (auto x : mp)
//                 {
//                     if (x.first != 1)
//                     {
//                         ans = ans + (x.first) * (1LL) * (x.second);
//                         count += x.second;
//                     }
//                 }
//                 cout << ans + (2 * K - count) << "\n";
//             }
//         }
//         long long count = 0;
//         for (int i = 1; i <= 1000000; ++i)
//         {
//             if (probablyPrimeFermat(4 * i + 1) == true)
//             {
//                 count++;
//             }
//         }
//         cout << count << "\n";
//         cout << a[4 * K + 1] << "\n";
//     }
// }