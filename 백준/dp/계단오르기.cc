#include <bits/stdc++.h>

using namespace std;
int n;
int a[300];
int dp[300];
int answer = 0;
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max(a[0] + a[2], a[1] + a[2]);
    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);

    }
    cout << dp[n-1];
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int n;
// int a[300];
// int dp[300];
// int answer = 0;

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     dp[0] = a[0];
//     dp[1] = a[0] + a[1];
//     dp[2] = max(dp[0] + a[2], a[1] + a[2]);
//     for (int i = 3; i < n; i++)
//     {
//         dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
//     }

//     cout << dp[n - 1] << '\n';
//     return 0;
// }

// // #include <bits/stdc++.h>

// // using namespace std;

// // int n;
// // int a[300];
// // int answer = 0;
// // void go(int pos, int result, int count)
// // {
// //     if (count == 3 || pos >= n)
// //         return;
// //     if (n - 1 == pos)
// //     {
// //         answer = max(result, answer);
// //         return;
// //     }
// //     go(pos + 1, result + a[pos + 1], count + 1);
// //     go(pos + 2, result + a[pos + 2], 1);
// // }

// // int main()
// // {
// //     cin >> n;
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> a[i];
// //     }
// //     go(0, a[0], 1);

// //     cout << answer << '\n';
// //     return 0;
// // }