#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> a;
    vector<int> index;
    int answer = 1000000001;
    int b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        index.push_back(0);
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            a[i].push_back(b);
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }

    while (1)
    {
        int class_num;
        int min_num = 1000000001;
        int max_num = 0;
        for (int i = 0; i < n; i++)
        {
            if (min_num > a[i][index[i]])
            {
                min_num = a[i][index[i]];
                class_num = i;
            }
            if (max_num < a[i][index[i]])
                max_num = a[i][index[i]];
        }

        answer = min(answer, max_num - min_num);
        index[class_num]++;
        if (index[class_num] == m)
            break;
    }

    cout << answer;

    return 0;
}