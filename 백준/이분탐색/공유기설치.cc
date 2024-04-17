#include <bits/stdc++.h>

using namespace std;
int n, c;
vector<int> a;
int answer = 0;

void go()
{
    int left = 1;         // 최소 간격
    int right = a[n-1]; // 최대간격 x1 = 0 도 가능

    while (left <= right)
    {
        // cout << "here";
        int install = 1;
        int mid = (left + right) / 2; // 간격 (target)
        int start = a[0];

        for (int i = 1; i < n; i++)
        {
            int end = a[i];
            if (mid <= (end - start))
            {
                start = end;
                install++;
            }

            if (c == install)
                break;
        }

        if (c > install) // 간격 줄이기
        {
            right = mid - 1;
        }
        else // 간격 키우기 c >= insall
        {
            answer = mid;
            left = mid + 1;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a.push_back(b);
    }

    sort(a.begin(), a.end());

    go();
    cout << answer;
    return 0;
}