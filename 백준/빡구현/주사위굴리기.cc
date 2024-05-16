#include <bits/stdc++.h>

using namespace std;

int m, n, x, y, k;
vector<vector<int>> a;
vector<int> cmd;
int dice[6] = {
    0,
}; // 0위,1아래,2동,3서,4남,5북

bool check(int d)
{
    int temp = dice[1];
    if (d == 1)
    {
        if (y == m - 1)
            return false;
        y++;
        dice[1] = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = temp;
        return true;
    }
    if (d == 2)
    {
        if (y == 0)
            return false;
        y--;
        dice[1] = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[2];
        dice[2] = temp;
        return true;
    }
    if (d == 3)
    {
        if (x == 0)
            return false;
        x--;
        dice[1] = dice[5];
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = temp;
        return true;
    }

    if (x == n - 1)
        return false;
    x++;
    dice[1] = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[5];
    dice[5] = temp;

    return true;
}

void play()
{
    for (int i = 0; i < cmd.size(); i++)
    {
        if (!check(cmd[i]))
            continue;
        if (a[x][y] == 0)
        {
            a[x][y] = dice[1];
        }
        else
        {
            dice[1] = a[x][y];
            a[x][y] = 0;
        }
        cout << dice[0] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    int b;
    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            a[i].push_back(b);
        }
    }
    int c;
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        cmd.push_back(c);
    }
    play();
    return 0;
}