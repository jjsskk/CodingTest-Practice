#include <bits/stdc++.h>

using namespace std;

int n, m, h;
bool visited[31][11] = {
    false,
};
int answer = -1;
bool catch1 = false;
bool check()
{
    for (int col = 1; col <= n; col++)
    {
        int first = col;
        for (int row = 1; row <= h; row++)
        {
            if (visited[row][first])
                first = first + 1;
            else if (visited[row][first - 1]) // 무조건 else if 하던가 continue;로 하나만 해야함!
                first = first - 1;
        }
        if (first != col)
            return false;
    }

    return true;
}
void dfs(int cnt, int add)
{
    if (cnt == add)
    {
        if (check())
        {
            answer = cnt;
            catch1 = true;
        }
        return;
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 1; i <= h; i++)
        {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
                continue;
            visited[i][j] = true; // 가로선 놓기
            dfs(cnt, add + 1);
            visited[i][j] = false; // 가로선 제거 -> 백트랙킹

            // 다음 가로선을 놓을 위치로 이동 -> 사다리 관점에서 보면 바로 다음 가로줄에 혹은 다다음 가로줄에 가로선 추가 해봐야 의미가 없음 (결과는 똑같에)
            //-> 차라리 아래에 존재하는 (j - 1 ->j) or (j -> j+1) 가로선 다음 위치를 바로 찾아서 추가 하면 다른 결과도 얻으면서 dfs를 훨씬 줄일 수 있음
            while (!visited[i][j - 1] && !visited[i][j + 1])
                i++;
        }
    }
}
int go()
{
    for (int i = 0; i < 4; i++)
    {
        if (catch1)
            break;
        dfs(i, 0);
    }

    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> h;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        visited[a][b] = true;
    }
    cout << go();
    return 0;
}