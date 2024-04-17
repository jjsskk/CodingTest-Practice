#include <bits/stdc++.h>

using namespace std;
int dp[100];

int t;
int fib(int n)
{
    if (dp[n] != -1)
        return dp[n];

    if (n < 2) // 여기 진짜 중요!!! 잘 선택해
    {
        dp[n] = n;
        return dp[n];
    }

    dp[n] = fib(n - 1) + fib(n - 2);

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> t;
    int b;
    for (int i = 0; i < t; i++)
    {
        cin >> b;
        fib(b - 1); // b=1일때 이거 없으면 안됨
        fib(b);
        if (b == 0)
            cout << 1 << " " << 0 << '\n';
        else
            cout << dp[b - 1] << " " << dp[b] << '\n';
    }
    return 0;
}