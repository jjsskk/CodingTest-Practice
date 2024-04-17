#include <bits/stdc++.h>

using namespace std;

int n;
int r;
vector<vector<int>> a;
bool selected[20];
int answer = 2147483647;
void go()
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (selected[i] == true && selected[j] == true)
                sum1 += (a[i][j]);
            if (selected[i] == false && selected[j] == false)
                sum2 += (a[i][j]);
        }
    }

    int diff = abs(sum1 - sum2);
    answer = min(diff, answer);
}
void combi(int start, int count)
{
    if (count == r)
    {
        go();
        return;
    }
    for (int i = start + 1; i < n; i++)
    {
        selected[i] = true;
        combi(i, count + 1);
        selected[i] = false;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            int m;
            cin >> m;
            a[i].push_back(m);
        }
    }
    r = n / 2;
    memset(selected, false, sizeof(selected));
    combi(-1, 0);
    cout << answer;
    return 0;
}
