#include <bits/stdc++.h>
using namespace std;
int arr[2021][2021];
void printPattern(int n)
{

    int k, i, j, p = 1, f;

    for (k = 0; k < n; k++)
    {
        j = k;
        i = 0;
        while (j >= 0)
        {
            arr[i][j] = p;
            p++;
            i = i + 1;
            j = j - 1;
        }
    }

    for (k = 1; k < n; k++)
    {
        i = k;
        j = n - 1;
        f = k;
        while (j >= f)
        {
            arr[i][j] = p;
            p++;
            i = i + 1;
            j = j - 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    printPattern(1010);
    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for (int i = x1; i <= x2; i++)
        {
            sum = sum + arr[i-1][y1-1];
        }
        for (int i = y1+1; i <= y2; i++)
        {
            sum = sum + arr[x2-1][i-1];
        }

        cout << sum << endl;
    }
    return 0;
}