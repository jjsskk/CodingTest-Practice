#include <bits/stdc++.h>

using namespace std;
int n, k, l;
int answer = 1;
queue<pair<int, int>> q; // 뱀의 몸 (y,x)
int m[101][101] = {
    0,
}; // 0 : 빈칸 1: 사과
int s[101];
char d[101];
const int dy[] = {0, 1, 0, -1}; // 동남서북 ( 시계방향)
const int dx[] = {1, 0, -1, 0}; // 동남서북
int cur_dir = 0;
bool check(int cur_y, int cur_x)
{
    int size = (int)q.size();
    for (int i = 0; i < size; i++)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (cur_y == y && cur_x == x)
            return false;
        q.push({y, x});
    }
    return true;
}
void eat(int y, int x)
{
    q.push({y, x});
    if (m[y][x] == 1)
    {
        m[y][x] = 0;
        return;
    }
    q.pop();
}
void play()
{
    q.push({0, 0});
    for (int i = 0; i < l; i++)
    {
        int cur_x = q.back().second;
        int cur_y = q.back().first;
        while (answer <= s[i] || i == l - 1) // 모든 명령 끝난후 뱀이 벽에 부딪힐떄까지 움직이도록 해야함
        {
            int ny = cur_y + dy[cur_dir];
            int nx = cur_x + dx[cur_dir];
            if (ny < 0 || nx < 0 || nx >= n || ny >= n)
                return;
            if (!check(ny, nx))
                return;
            cur_x = nx;
            cur_y = ny;
            answer++;
            eat(ny, nx);

            if (d[i] == 'L' && answer == s[i] + 1)
            // 가장 마지막 명령에서 while문을 빠져나가지 못하기 떄문에 방향전환 기능은 무조건 while문 안에 있어야함
            {
                cur_dir--;
                if (cur_dir == -1)
                    cur_dir = 3;
            }
            else if (d[i] == 'D' && answer == s[i] + 1)
            {
                cur_dir++;
                if (cur_dir == 4)
                    cur_dir = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    int a, h;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> h;
        m[a - 1][h - 1] = 1;
    }

    cin >> l;
    int b;
    char c;
    for (int i = 0; i < l; i++)
    {
        cin >> b >> c;
        s[i] = b;
        d[i] = c;
    }

    play();
    cout << answer;
    return 0;
}