#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> a;
    priority_queue<pair<int, pair<int, int>>> pq;
    int min_num = 1000000001;
    int answer = 1000000001;
    int b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        a.emplace_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            cin >> b;
            a[i].push_back(b);
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end(), greater<int>());
        min_num = min(a[i][0], min_num);
        pq.push({a[i][0], {i, 0}}); // 능력치, {반 번호, 학생 번호}
    }

    while (1)
    {
        int max_num = pq.top().first;
        int class_num = pq.top().second.first;
        int student_num = pq.top().second.second;
        pq.pop();

        int result = max_num - min_num;
        answer = min(answer, result);

        if (student_num + 1 == m)
            break;
        min_num = min(min_num, a[class_num][student_num + 1]);
        pq.push({a[class_num][student_num + 1], {class_num, student_num + 1}});
    }

    cout << answer;

    return 0;
}