// 에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾는 유명한 알고리즘이다.
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    bool a[1000001] = {
        false, // false이면 소수로 간주 2 -> 소수
    };
    a[0] = true, a[1] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
            continue;
        for (int j = 2; i * j <= n; j++)
        {
            a[i * j] = true;
        }
    }
    int count = 0;
    int answer;
    for (int i = m; i <= n; i++)
    {
        if (!a[i])
        {
            cout << i << '\n';
        }
    }

    return 0;
}