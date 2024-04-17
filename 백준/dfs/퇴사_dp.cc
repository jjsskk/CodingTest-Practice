#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int>> sches;
int dp[16];
int answer = 0;
void DP()
{
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; 0 <= i; i--)
    {
        int pos = i + sches[i].first;
        if (pos <= n)
            dp[i] = max(dp[pos] + sches[i].second, dp[i + 1]);
        else
            dp[i] = dp[i + 1];
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        sches.push_back({f, s});
    }
    DP();
    cout << dp[0] << '\n';
    return 0;
}