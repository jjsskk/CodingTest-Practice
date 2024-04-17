// #include <bits/stdc++.h>

// using namespace std;
// int t;
// long long dp[101] = {
//     0,
//     1,
//     1,
//     1,
//     2,
// };
// long long answer(int a)
// {
//     if (a < 5)
//         return dp[a];

//     for (int i = 5; i < a + 1; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 5];
//     }
//     return dp[a];
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin >> t;
//     int a;

//     for (int i = 0; i < t; i++)
//     {
//         cin >> a;
//         cout << answer(a) << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
int t;
long long dp[101] = {
    1,
    1,
    1,
};
long long answer(int a)
{
    if (a < 3)
        return dp[a-1];
    for (int i = 3; i < a; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    return dp[a - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    int a;

    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cout << answer(a) << '\n';
    }

    return 0;
}