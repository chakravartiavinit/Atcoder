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
        int spaces=0;
        string a, b, c;
        cin >> a >> b >> c;
        a = a + b + c;
        int x = 0;
        int o = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == 'X')
            {
                x++;
            }
            else if (a[i] == 'O')
            {
                o++;
            }
            else if (a[i] == '_')
            {
                spaces++;
            }
        }

        int flag1 = 0, flag2 = 0;
        //diagonals
        if (a[0] == a[4] && a[4] == a[8] && a[0] != '_')
        {
            if (a[0] == 'X')
            {
                flag1++;
            }
            else if (a[0] == 'O')
            {
                flag2++;
            }
        }

        if (a[2] == a[4] && a[4] == a[6] && a[2] != '_')
        {
            if (a[2] == 'X')
            {
                flag1++;
            }
            else if (a[2] == 'O')
            {
                flag2++;
            }
        }
        //straight line conditions

        if (a[0] == a[3] && a[3] == a[6] && a[0] != '_')
        {
            if (a[0] == 'X')
            {
                flag1++;
            }
            else if (a[0] == 'O')
            {
                flag2++;
            }
        }

        if (a[1] == a[4] && a[4] == a[7] && a[1] != '_')
        {
            if (a[1] == 'X')
            {
                flag1++;
            }
            else if (a[1] == 'O')
            {
                flag2++;
            }
        }

        if (a[2] == a[5] && a[5] == a[8] && a[2] != '_')
        {
            if (a[2] == 'X')
            {
                flag1++;
            }
            else if (a[2] == 'O')
            {
                flag2++;
            }
        }

        if (a[0] == a[1] && a[1] == a[2] && a[0] != '_')
        {
            if (a[0] == 'X')
            {
                flag1++;
            }
            else if (a[0] == 'O')
            {
                flag2++;
            }
        }

        if (a[3] == a[4] && a[4] == a[5] && a[3] != '_')
        {
            if (a[3] == 'X')
            {
                flag1++;
            }
            else if (a[3] == 'O')
            {
                flag2++;
            }
        }

        if (a[6] == a[7] && a[7] == a[8] && a[6] != '_')
        {
            if (a[6] == 'X')
            {
                flag1++;
            }
            else if (a[6] == 'O')
            {
                flag2++;
            }
        }
        // auto it = find(a.begin(), a.end(), '_');
        // conditions for the various cases
        if ((o > x) || (x - o) > 1 || (flag1 == 1 && flag2 == 1))
        {
            cout << 3 << endl;
        }
        else if (x > o && flag1 == 1 && flag2 == 0)
        {
            cout << 1 << endl;
        }
        else if (x == o && flag1 == 0 && flag2 == 0)
        {
            cout << 1 << endl;
        }
        else if (spaces == 0 && flag1 == 0 && flag2 == 0)
        {
            cout << 1 << endl;
        }
        else if (spaces > 0 && flag1 == 0 && flag2 == 0)
        {
            cout << 2 << endl;
        }
        else if (spaces == 0 && flag1 == 2)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }
    return 0;
}