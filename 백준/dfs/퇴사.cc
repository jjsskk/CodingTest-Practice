#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> sche;
int n;
int max_result = 0;

void dfs(int pay, int i)
{
    if (i > n)
    {
        return;
    }

    max_result = max(max_result, pay);
    for (; i < sche.size(); i++)
    {
        dfs(pay + sche[i].second, i + sche[i].first);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, p;
        cin >> t >> p;
        sche.push_back({t, p});
        // cout<< t << p << '\n' ;
    }
    dfs(0, 0);
    cout << max_result << '\n';
    return 0;
}
