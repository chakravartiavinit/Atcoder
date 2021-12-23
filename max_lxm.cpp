#include <iostream>
using namespace std;
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        long long g;
        cin >> g;
        long long fact = (1000000000) / g;
        long long ans;
        if (fact == 1)
        {
            ans = g * (1LL) * fact;
        }
        else
        {
            ans = g * (1LL) * fact * (1LL) * (fact - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}