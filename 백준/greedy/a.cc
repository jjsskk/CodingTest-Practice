#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> crystal;

int bag[300000];
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long answer = 0;
    int n, k;

    cin >> n >> k;

    int m, v;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        // cout << m << v<< '\n';
        crystal.push_back({m, v});
    }

    int c;
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag[i] = c;
    }

    sort(crystal.begin(), crystal.end()); // 무게별로 정렬
    sort(bag, bag + k);

    int index = 0;
    for (int i = 0; i < k; i++) // 가방 별로 정렬 k -> 가방 개수
    {
        while (index < n && crystal[index].first <= bag[i]) // n 보석개수
        {
            pq.push(crystal[index].second); // 가격 을 넣음
            index++;
        }
        if (pq.empty())
            continue;

        answer += pq.top();
        pq.pop();
    }

    cout << answer << '\n';
    return 0;
}