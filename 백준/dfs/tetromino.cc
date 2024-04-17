#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
int visited[500][500];
int n, m;
int answer = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {
    1,
    -1,
    0,
    0,
};
void dfs(int y, int x, int result, int count)
{
    if (count == 4)
    {
        answer = max(result, answer);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[ny][nx] == 1)
            continue;
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, result + a[ny][nx], count + 1);
        visited[ny][nx] = 0;
    }

    // ㅗㅜㅏㅓ
    if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < m)
        answer = max(answer, a[y][x] + a[y - 1][x] + a[y][x - 1] + a[y][x + 1]);
    if (y + 1 < n && x - 1 >= 0 && x + 1 < m)
        answer = max(answer, a[y][x] + a[y + 1][x] + a[y][x - 1] + a[y][x + 1]);
    if (y - 1 >= 0 && x + 1 < m && y + 1 < n)
        answer = max(answer, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x + 1]);
    if (y - 1 >= 0 && x - 1 >= 0 && y + 1 < n)
        answer = max(answer, a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x - 1]);
}

void go()
{
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 1;
            dfs(i, j, a[i][j], 1);
            visited[i][j] = 0;
        }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            int aa;
            cin >> aa;
            a[i].push_back(aa);
        }
    }
    go();
    cout << answer;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// int n, m;
// int answer = 0;
// vector<vector<int>> a;
// int visited[500][500];
// typedef struct
// {
//     int x, y;
// } TwoD;

// TwoD twoD[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// void dfs(int y, int x, int result, int cnt)
// {
//     if (cnt == 4)
//     {
//         answer = max(answer, result);
//         return;
//     }
//     // visited[y][x] = 1;
//     // answer = max(answer, result); -> 이것도 정답 처리 됨
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + twoD[i].x;
//         int ny = y + twoD[i].y;
//         if (visited[ny][nx] == 1)
//             continue;
//         if (nx < 0 || ny < 0 || nx >= m || ny >= n)
//             continue;
//         visited[ny][nx] = 1;
//         dfs(ny, nx, result + a[ny][nx], cnt + 1); // 뱀모양만 가능함
//         visited[ny][nx] = 0;                      // 백트레킹
//     }
//     // ㅗ / ㅏ / ㅜ / ㅓ의 블록은 따로 계산.
//     // 해당 블록들은 깊이 4인 DFS로는 만들어 낼 수 없기 때문
//     if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < n) // ㅓ
//     {
//         answer = max(answer, a[y][x] + a[y][x - 1] + a[y + 1][x] + a[y - 1][x]);
//     }
//     if (x + 1 < m && y + 1 < n && y - 1 >= 0) // ㅏ
//     {
//         answer = max(answer, a[y][x] + a[y][x + 1] + a[y + 1][x] + a[y - 1][x]);
//     }
//     if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < m) // ㅗ
//     {
//         answer = max(answer, a[y][x] + a[y - 1][x] + a[y][x - 1] + a[y][x + 1]);
//     }
//     if (x - 1 >= 0 && x + 1 < m && y + 1 < n) // ㅜ
//     {
//         answer = max(answer, a[y][x] + a[y][x - 1] + a[y][x + 1] + a[y + 1][x]);
//     }
// }

// void go()
// {

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             // memset(visited, 0, sizeof(visited)); //-> 시간 초과 원인 인듯
//             visited[i][j] = 1;
//             dfs(i, j, a[i][j], 1);
//             visited[i][j] = 0; // 백트레킹
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;

//     for (int i = 0; i < n; i++) // y
//     {
//         a.emplace_back(vector<int>());
//         for (int j = 0; j < m; j++) // x
//         {
//             int b;
//             cin >> b;
//             a[i].push_back(b);
//         }
//     }

//     // for (auto b : a)
//     // {
//     //     for (auto c : b)
//     //         cout << c;
//     //         cout<<'\n';
//     // }
//     go();
//     cout << answer << '\n';
//     return 0;
// }