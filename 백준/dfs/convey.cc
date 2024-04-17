#include <bits/stdc++.h>

using namespace std;
int n, k;
int up, down;
int cnt = 0; // 내구도 0인 칸 개수 세기
vector<int> a;
bool visited[201] = {
    false,
};
queue<int> q; // 로봇의 위치
void make_robot()
{
    if (a[up] != 0)
    {
        q.push(up);
        a[up]--;
        visited[up] = true;
        if (a[up] == 0)
            cnt++;
    }
}
void move_robot()
{
    int len = q.size();
    for (int i = 0; i < len; i++)
    {
        int pos = q.front();
        q.pop();

        int next = pos + 1;
        visited[pos] = false;

        if (pos == down) // 벨트 이동에 의해 내리는칸 도착시 내림
            continue;

        if (next > 2 * n)
            next = 1;

        if (a[next] != 0 && visited[next] == false)
        {
            a[next]--;
            if (a[next] == 0)
                cnt++;
            if (next == down) // 로봇의 이동에 의해 내리는칸에 도착시 내림 -> 내리는칸이 내구도 0이면 이동x ( 컨베이어 벨트 이동에 의해서 내려야 함)
                continue;
            visited[next] = true;
            q.push(next);
        }
        else
        {
            visited[pos] = true;
            q.push(pos);
        }
    }
}
void move_belt()
{
    up--;
    down--;
    if (up == 0)
        up = 2 * n;

    if (down == 0)
        down = 2 * n;
}
int solve()
{
    int answer = 0;
    up = 1;
    down = n;
    while (cnt < k)
    {
        answer++;
        move_belt();
        move_robot();
        make_robot();
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    int size = 2 * n;
    int b;
    a.push_back(1); // 인덱스 0
    for (int i = 0; i < size; i++)
    {
        cin >> b;
        a.push_back(b);
    }

    cout << solve();
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// int n, k;
// vector<int> a;
// vector<bool> visited; // robot
// queue<int> q;
// int cnt = 0;

// void move_robot(int down)
// {
//     int num = q.size();
//     for (int i = 0; i < num; i++)
//     {
//         int index = q.front();
//         q.pop();
//         int next = index + 1;
//         if (index == down - 1) // 내리는 칸 by 컨베이밸트 이동
//         {
//             visited[index] = false;
//             continue;
//         }
//         if (next >= 2 * n)
//             next = 0;

//         if (a[next] <= 0) // 앞칸 내구도 0
//         {
//             q.push(index);
//             continue;
//         }
//         if (visited[next] == true) // 앞칸에 로봇이 존재
//         {
//             q.push(index);
//             continue;
//         }
//         a[next]--;
//         if (a[next] <= 0)
//             cnt++;
//         if (next == down - 1) // 내리는 칸 by 로봇의 이동 (컨베이 이동은 관여x)
//         {
//             visited[index] = false;
//             continue;
//         }
//         q.push(next); // 앞칸 이동
//         visited[next] = true;
//         visited[index] = false;
//     }
// }
// void make_robot(int up)
// {

//     if (a[up - 1] > 0 && visited[up - 1] == false)
//     {
//         q.push(up - 1);
//         a[up - 1]--;
//         visited[up - 1] = true;
//         if (a[up - 1] <= 0)
//             cnt++;
//     }
// }

// int move()
// {
//     int up = 1;
//     int down = n;
//     int answer = 0;
//     while (cnt < k)
//     {
//         up--;
//         down--;
//         if (up == 0)
//             up = 2 * n;
//         if (down == 0)
//             down = 2 * n;

//         answer++;
//         move_robot(down);
//         make_robot(up);
//     }

//     return answer;
// }
// int main()
// {
//     cin >> n >> k;
//     int b;
//     for (int i = 0; i < 2 * n; i++)
//     {
//         cin >> b;
//         a.push_back(b);
//         visited.push_back(false);
//     }

//     cout << move();
//     return 0;
// }