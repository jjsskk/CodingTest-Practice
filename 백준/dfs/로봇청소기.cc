#include <bits/stdc++.h>

using namespace std;
int n, m;
pair<int, int> start;
int visited[51][51];
int start_dir;
const int dy[] = {-1, 0, 1, 0}; // 북서남동
const int dx[] = {0, -1, 0, 1};
int answer = 0;

void dfs(vector<vector<int>> &a, int y, int x, int cur_dir, bool go)
{
    if (go)
        answer++;
    int next_dir = cur_dir;
    for (int i = 0; i < 4; i++)
    {
        next_dir++;
        if (next_dir == 4)
            next_dir = 0;
        int ny = y + dy[next_dir];
        int nx = x + dx[next_dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (a[ny][nx] == 1 || visited[ny][nx] == 1)
            continue;
        visited[ny][nx] = 1;
        // cur_dir = next_dir;
        dfs(a, ny, nx, next_dir, true);
    } // 4방면 다 체크했으니까 이후에 뒤로 가는것도 dfs로해도 무방!(바로보는 방향을 유지해야 하니까)

    int pre_idx = cur_dir + 2 < 4 ? cur_dir + 2 : cur_dir - 2;
    int pre_x = x + dx[pre_idx];
    int pre_y = y + dy[pre_idx];
    if (pre_x >= 0 && pre_y >= 0 && pre_x < m && pre_y < n)
    {
        if (a[pre_y][pre_x] == 0)
        {
            dfs(a, pre_y, pre_x, cur_dir, false);
        }
        else
        {
            cout << answer;
            exit(0);
        }
    }
}
int main()
{
    vector<vector<int>> a;
    cin >> n >> m;
    cin >> start.first >> start.second >> start_dir;
    int x;
    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            a[i].push_back(x);
        }
    }
    memset(visited, 0, sizeof(visited));
    int dir = 0;
    if (start_dir == 0)
        dir = 0;
    else if (start_dir == 1)
        dir = 3;
    else if (start_dir == 2)
        dir = 2;
    else
        dir = 1;

    visited[start.first][start.second] = 1;
    dfs(a, start.first, start.second, dir, true);
    cout << answer;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// int n, m;
// pair<int, int> start;
// int visited[51][51];
// int start_dir;
// const int dy[] = {-1, 0, 1, 0}; // 북서남동
// const int dx[] = {0, 1, 0, -1};
// int answer = 0;
// // int cur_dir;
// void dfs(vector<vector<int>> &a, int y, int x, int cur_dir, int count, bool go)
// {
//     if (go)
//         answer++;
//     // int next_dir = cur_dir;
//     for (int i = 0; i < 4; i++)
//     {
//         // next_dir++;
//         // if (next_dir == 4)
//             // next_dir = 0;
//         int next_dir = (cur_dir+3-i)%4;
//         int ny = y + dy[next_dir];
//         int nx = x + dx[next_dir];

//         if (ny < 0 || nx < 0 || ny >= n || nx >= m)
//             continue;
//         if (a[ny][nx] == 1 || visited[ny][nx] == 1)
//             continue;
//         visited[ny][nx] = 1;
//         // cur_dir = next_dir;
//         dfs(a, ny, nx, next_dir, count + 1, true);
//     } // 4방면 다 체크했으니까 이후에 뒤로 가는것도 dfs로해도 무방!(바로보는 방향을 유지해야 하니까)

//     int pre_idx = cur_dir + 2 < 4 ? cur_dir + 2 : cur_dir - 2;
//     int pre_x = x + dx[pre_idx];
//     int pre_y = y + dy[pre_idx];
//     if (pre_x >= 0 && pre_y >= 0 && pre_x < m && pre_y < n)
//     {
//         if (a[pre_y][pre_x] == 0)
//         {
//             dfs(a, pre_y, pre_x, cur_dir, count, false);
//         }
//         else
//         {
//             cout << answer;
//             exit(0);
//         }
//     }
// }
// int main()
// {
//     vector<vector<int>> a;
//     cin >> n >> m;
//     cin >> start.first >> start.second >> start_dir;
//     int x;
//     for (int i = 0; i < n; i++)
//     {
//         a.emplace_back(vector<int>());
//         for (int j = 0; j < m; j++)
//         {
//             cin >> x;
//             a[i].push_back(x);
//         }
//     }
//     memset(visited, 0, sizeof(visited));
//     // int dir = 0;
//     // if (start_dir == 0)
//     //     dir = 0;
//     // else if (start_dir == 1)
//     //     dir = 4;
//     // else if (start_dir == 2)
//     //     dir = 2;
//     // else
//     //     dir = 1;
//     // cur_dir = dir;
//     visited[start.first][start.second] = 1;
//     dfs(a, start.first, start.second, start_dir, 1, true);
//     cout << answer;
//     return 0;
// }