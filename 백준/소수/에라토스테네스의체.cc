// 에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾는 유명한 알고리즘이다.
#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    bool a[1001] = {
        false, // false이면 소수로 간주 2 -> 소수
    };
    a[0] = true, a[1] = true;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i])
            continue;
        for (int j = 1; i * j <= n; j++)
        {
            if (a[i * j])
                continue;
            count++;
            a[i * j] = true;
            if (count == k)
            {
                cout << j * i;
                return 0;
            }
        }
    }


    return 0;
}