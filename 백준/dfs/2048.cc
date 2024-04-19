#include <bits/stdc++.h>

using namespace std;
int n;
int answer = 0;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
void rotate(vector<vector<int>> &a)
{
    int temp[20][20];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = a[n - j - 1][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = temp[i][j];
        }
    }
}
int getMax(vector<vector<int>> &a)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ret < a[i][j])
                ret = a[i][j];
        }
    }

    return ret;
}
void up(vector<vector<int>> &a)
{
    int temp[20][20];

    for (int j = 0; j < n; j++)
    {
        int flag = 0, target = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 0)
                continue;
            if (flag == 1 && a[i][j] == temp[target][j])
            {
                temp[target][j] *= 2;
                flag = 0;
            }
            else
            {
                temp[++target][j] = a[i][j];
                flag = 1;
            }
        }

        for (++target; target < n; target++)
        {
            temp[target][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = temp[i][j];
        }
    }
}
void dfs(vector<vector<int>> current, int count)
{
    if (count == 5)
    {
        answer = max(answer, getMax(current));
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> next(current);
        up(next); // up시킨건 next에만 저장되야함
        dfs(next, count + 1);
        rotate(current);
    }
}

int main()
{
    vector<vector<int>> a;
    cin >> n;
    int b;

    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            cin >> b;
            a[i].push_back(b);
        }
    }
    dfs(a, 0);
    cout << answer;

    return 0;
}