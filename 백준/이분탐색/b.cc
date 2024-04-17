#include <bits/stdc++.h>

using namespace std;

int n, m;
int answer = 0;
vector<int> a;
void go()
{
    int left = 0;
    int right = 1000000000;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long tree_len = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid < a[i])
            {
                tree_len += (long long)(a[i] - mid);
            }
        }

        if (tree_len < m) // 더많은 나무길이 필요 -> target < mid
        {
            right = mid - 1;
        }
        else // target > mid
        {
            left = mid + 1;
            answer = mid;
        }
    }
}

int main()
{
    cin >> n >> m;
    int b;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    go();
    cout << answer;
    return 0;
}