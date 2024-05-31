#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> a;
vector<pair<int, int>> cctv;
bool visited[10][10] = {false};
int n, m;
int cnt = 64;
const int dy[] = {0, 1, 0, -1}; // 오 아 왼 위
const int dx[] = {1, 0, -1, 0};
void check(int y, int x, int idx)
{
    idx %= 4;
    while (1)
    {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        x = nx;
        y = ny;

        if (y < 0 || x < 0 || x >= m || y >= n)
            return;
        if (a[y][x] == 6) // 벽
            return;
        if (a[y][x] != 0)
            continue;
        if (a[y][x] == 0)
            a[y][x] = -1; // -1 = #
    }
}
void dfs(int idx)
{
    if (idx == cctv.size())
    {
        int temp_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                    temp_cnt++;
            }
        }
        cnt = min(cnt, temp_cnt);

        return;
    }

    int y = cctv[idx].first;
    int x = cctv[idx].second;
    vector<vector<int>> backup;
    for (int i = 0; i < n; i++)
    {
        backup.emplace_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            backup[i].push_back(a[i][j]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (a[y][x] == 1)
        {
            check(y, x, i); // cctv 가능한 감시 방향 #으로 색칠
        }
        else if (a[y][x] == 2)
        {
            check(y, x, i);
            check(y, x, i + 2);
        }
        else if (a[y][x] == 3)
        {
            check(y, x, i);
            check(y, x, i + 1);
        }
        else if (a[y][x] == 4)
        {
            check(y, x, i);
            check(y, x, i + 1);
            check(y, x, i + 2);
        }
        else if (a[y][x] == 5)
        {
            check(y, x, i);
            check(y, x, i + 1);
            check(y, x, i + 2);
            check(y, x, i + 3);
        }
        dfs(idx + 1);
        // 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = backup[i][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int c;
    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            a[i].push_back(c);
            if (c != 0 && c != 6)
                cctv.push_back({i, j});
        }
    }
    dfs(0);
    cout << cnt;
    return 0;
}