#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[500][500];
int dp[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int y, int x)
{
    if (y == n - 1 && x == m - 1)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        if (a[y][x] > a[ny][nx]) // visited 체크 안해도 방문한 경로가 여기서.... 걸러 걸러!
        {
            dp[y][x] = dfs(ny, nx) + dp[y][x];
        }
    }
    
    return dp[y][x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    
    dfs(0,0);
    cout<<dp[0][0];
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int n, m;

// int a[500][500];
// int dp[500][500];

// typedef struct
// {
//     int x, y;
// } TwoD;

// TwoD twoD[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// int
// dfs(int y, int x)
// {
//     if (y == n - 1 && x == m - 1)
//         return 1;
//     if (dp[y][x] != -1)
//         return dp[y][x];

//     dp[y][x] = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + twoD[i].x;
//         int ny = y + twoD[i].y;

//         if (ny < 0 || nx < 0 || ny >= n || nx >= m)
//             continue;
//         if (a[y][x] > a[ny][nx])
//         {
//             dp[y][x] = dp[y][x] + dfs(ny, nx);
//         }
//         // dfs
//     }

//     return dp[y][x];
// }

// int main()
// {
//     cin >> n >> m;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     memset(dp, -1, sizeof(dp));

//     cout << dfs(0, 0) << '\n';

//     return 0;
// }