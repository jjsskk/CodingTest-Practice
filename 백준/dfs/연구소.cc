//연구소
#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[10][10], visited[10][10];
vector<pair<int, int>> zero, vir;

typedef struct
{
    int x, y;
} TwoD;
TwoD twoD[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + twoD[i].x;
        int ny = y + twoD[i].y;

        if (visited[ny][nx])
            continue;
        if (nx < 0 || ny < 0 || n <= ny || m <= nx)
            continue;
        if (a[ny][nx] == 1) // 기존의 벽
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int go()
{
    int cnt = 0;

    memset(visited, 0, sizeof(visited));
    for (pair<int, int> v : vir)
    {
        visited[v.first][v.second] = 1;
        dfs(v.first, v.second); // virus spread
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 0 && visited[i][j] == 0)
                cnt++;
    return cnt;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) // i,n :세로
    {
        for (int j = 0; j < m; j++) // j,m : 가로
        {
            cin >> a[i][j];

            if (a[i][j] == 0)
                zero.push_back({i, j});
            if (a[i][j] == 2)
                vir.push_back({i, j});
        }
    }
    int len = zero.size();
    int answer = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                a[zero[i].first][zero[i].second] = 1;
                a[zero[j].first][zero[j].second] = 1;
                a[zero[k].first][zero[k].second] = 1;
                answer = max(answer, go());
                a[zero[i].first][zero[i].second] = 0;
                a[zero[j].first][zero[j].second] = 0;
                a[zero[k].first][zero[k].second] = 0;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}