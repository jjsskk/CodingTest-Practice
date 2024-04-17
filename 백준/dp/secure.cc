#include <bits/stdc++.h>
#define mod 1000000
using namespace std;
string a;
int len;
int c[5001];
int dp[5001];
int answer = 0;
void go()
{
    if (len == 1 && c[0] == 0)
        return;
    if (1 <= c[0] && c[0] <= 9)
        dp[0] = 1;
    else
        dp[0] = 0;
   
    for (int i = 1; i < len; i++)
    {
        if (1 <= c[i] && c[i] <= 9)
            dp[i] = (dp[i - 1] + dp[i]) % mod;

        int temp = c[i - 1] * 10 + c[i];
        if (i == 1)
        {
            if (temp <= 26 && temp >= 10)
                dp[i] = dp[i] + 1;
            continue;
        }
        if (temp <= 26 && temp >= 10)
            dp[i] = (dp[i - 2] + dp[i]) % mod;
    }

    answer = dp[len - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    len = a.length();
    for (int i = 0; i < len; i++)
    {
        c[i] = a[i] - '0';
    }

    go();
    cout << answer;
    return 0;
}