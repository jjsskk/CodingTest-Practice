#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        string c;
        int m;
        cin >> c;
        if (c == "add")
        {
            cin >> m;
            s |= (1 << m);
            continue;
        }
        if (c == "remove")
        {
            cin >> m;
            s &= ~(1 << m);
            continue;
        }
        if (c == "check")
        {
            cin >> m;
            if (s & (1 << m))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }
        if (c == "toggle")
        {
            cin >> m;
            if (s & (1 << m))
                s &= ~(1 << m);
            else
                s |= (1 << m);
            continue;
        }
        if (c == "all")
        {
            s = (1 << 21) - 1;
            continue;
        }
        if (c == "empty")
        {
            s = 0;
            continue;
        }
    }

    return 0;
}