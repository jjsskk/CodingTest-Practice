#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a[3][3] =
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << '\n';
    }
    int temp[3][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = a[n - j - 1][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< temp[i][j];
        }
        cout << '\n';
    }
    return 0;
}