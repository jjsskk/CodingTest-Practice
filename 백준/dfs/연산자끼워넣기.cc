#include <bits/stdc++.h>

using namespace std;

int nums[11], opers[4];
long long max_ans = -1000000001;
long long min_ans = 1000000001;
int n;
void dfs(long long result, int p)
{
    if (p == n)
    {
        max_ans = max(max_ans, result);
        min_ans = min(min_ans, result);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (opers[i] == 0)
        {
            continue;
        }
        opers[i]--;
        if (i == 0)
        {
            dfs(result + nums[p], p + 1);
        }
        if (i == 1)
        {
            dfs(result - nums[p], p + 1);
        }
        if (i == 2)
        {
            dfs(result * nums[p], p + 1);
        }
        if (i == 3)
        {
            dfs(result / nums[p], p + 1);
        }
        opers[i]++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        // cout<< nums[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> opers[i]; // + - / *
        // cout<< opers[i];
    }
    // cout<<'\n';

    dfs((long long)nums[0], 1);

    cout << max_ans << '\n';
    cout << min_ans << '\n';
    return 0;
}
