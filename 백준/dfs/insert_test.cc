#include <bits/stdc++.h>

using namespace std;

int n;
int nums[11], opers[4];
long long max_result = -1000000001;
long long min_result = 1000000001;

void dfs(long long mid, int index)
{
    if (index == n)
    {
        max_result = max(max_result, mid);
        min_result = min(min_result, mid);
        return;
    }

    for (int i = 0; i < 4; i++) // + - * /
    {
        if (opers[i] == 0)
            continue;
        opers[i]--;
        if (i == 0)
            dfs(mid + nums[index], index + 1);
        if (i == 1)
            dfs(mid - nums[index], index + 1);
        if (i == 2)
            dfs(mid * nums[index], index + 1);
        if (i == 3)
            dfs(mid / nums[index], index + 1);
        opers[i]++;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> opers[i];
    }

    dfs(nums[0], 1);
    cout << max_result << '\n';
    cout << min_result << '\n';

    return 0;
}