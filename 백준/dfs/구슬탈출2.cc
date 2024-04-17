// 구슬 탈출2

// 시간복잡도
//  4 * 2 ^ 9
//  왜 4^10이 아닌가?
//-> 처음에 4방향 그다음 중력에 따라 쭉 가버리면 방금 온 방향(ex 왼쪽)과 반대 반향(ex 오른쪽 다시 돌아가면 같은 위치니까)을 제회한 나머지 2가지 방향(위 아래)만 고려함(2^9)
// 여기서 최대 보드의 길이 10 곱하면
//  4*2^9*10 = 20480

#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef struct
{
    int rx, ry, bx, by, cnt;
} pos;
pos cur_pos;
vector<string> a;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool visited[11][11][11][11] = {
    false,
};
int bfs()
{
    queue<pos> q;
    q.push(cur_pos);
    int answer = -1; // 이거 진짜 중요 -> 레드 주위가 사방이 #이면 cnt가 10을 초과해서가 아닌 큐의 엠티로 불가능이 판단 되서 루프 나옴
    while (!q.empty())
    {
        pos temp = q.front();
        q.pop();
        if (temp.cnt > 10)
            break;

        if (a[temp.ry][temp.rx] == 'O' && a[temp.by][temp.bx] != 'O')
        {
            answer = temp.cnt;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int bdx = temp.bx;
            int bdy = temp.by;
            int rdx = temp.rx;
            int rdy = temp.ry;

            while (true)
            {
                if (a[rdy][rdx] != '#')
                {
                    if (a[rdy][rdx] == 'O')
                        break;
                    rdy += dy[i];
                    rdx += dx[i];
                }
                else
                {
                    rdy -= dy[i];
                    rdx -= dx[i];
                    break;
                }
            }
            while (true)
            {
                if (a[bdy][bdx] != '#')
                {
                    if (a[bdy][bdx] == 'O')
                        break;
                    bdy += dy[i];
                    bdx += dx[i];
                }
                else
                {
                    bdy -= dy[i];
                    bdx -= dx[i];
                    break;
                }
            }
            if (a[bdy][bdx] == 'O') // 여기서 파란구슬 구멍 혹은 빨간 & 파란 구슬 구멍이 모두 걸러짐
            {
                visited[rdy][rdx][bdy][bdx] = true;
                continue;
            }
            // if (a[rdy][rdx] == 'O' && a[bdy][bdx] == 'O')
            // {
            //     visited[rdy][rdx][bdy][bdx] = true;
            //     continue;
            // }
            if (rdy == bdy && rdx == bdx)
            {
                int bdis = abs(bdx - temp.bx) + abs(bdy - temp.by);
                int rdis = abs(rdx - temp.rx) + abs(rdy - temp.ry);
                if (rdis > bdis)
                {
                    rdx -= dx[i];
                    rdy -= dy[i];
                }
                else
                {
                    bdy -= dy[i];
                    bdx -= dx[i];
                }
            }

            if (visited[rdy][rdx][bdy][bdx] == true)
                continue;
            visited[rdy][rdx][bdy][bdx] = true;
            pos r;
            r.ry = rdy;
            r.rx = rdx;
            r.by = bdy;
            r.bx = bdx;
            r.cnt = temp.cnt + 1;
            q.push(r);
        }
    }
    return answer;
}

int main()
{
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'R')
            {
                cur_pos.ry = i;
                cur_pos.rx = j;
            }
            if (a[i][j] == 'B')
            {
                cur_pos.by = i;
                cur_pos.bx = j;
            }
        }
    }
    cur_pos.cnt = 0;
    visited[cur_pos.ry][cur_pos.rx][cur_pos.by][cur_pos.bx] = true;
    cout << bfs();
    return 0;
}