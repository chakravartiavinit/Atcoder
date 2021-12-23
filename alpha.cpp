#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        string a, b, c;
        cin >> a >> b >> c;
        a = a + b + c;
        int x = 0;
        int o = 0;
        for (int i = 0; i <= a.size() - 1; i++)
        {
            if (a[i] == 'X')
            {
                x++;
            }
            else if (a[i] == 'O')
            {
                o++;
            }
        }

        int flag = 0;
        //diagonals
        if (a[0] == a[4] && a[4] == a[8] && a[0] != '_')
        {
            flag++;
        }

        if (a[2] == a[4] && a[4] == a[6] && a[2] != '_')
        {
            flag++;
        }
        //straight line conditions

        if (a[0] == a[3] && a[3] == a[6] && a[0] != '_')
        {
            flag++;
        }

        if (a[1] == a[4] && a[4] == a[7] && a[1] != '_')
        {
            flag++;
        }

        if (a[2] == a[5] && a[5] == a[8] && a[2] != '_')
        {
            flag++;
        }

        if (a[0] == a[1] && a[1] == a[2] && a[0] != '_')
        {
            flag++;
        }

        if (a[3] == a[4] && a[4] == a[5] && a[3] != '_')
        {
            flag++;
        }

        if (a[6] == a[7] && a[7] == a[8] && a[6] != '_')
        {
            flag++;
        }
        auto it = find(a.begin(), a.end(), '_');

        if (o <= x && (x - o) <= 1)
        {
            if (flag == 1)
            {
                cout << 1 << endl;
            }
            else if (flag == 0 && it == a.end())
            {
                cout << 1 << endl;
            }
            else if (flag == 0 && it != a.end())
            {
                cout << 2 << endl;
            }
        }
        else
        {
            cout << 3 << endl;
        }
    }
    return 0;
}