// 보석 도둑
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> crystal;
int c[300001];

bool compair(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    cin >> n >> k;
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        crystal.push_back({m, v});
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }

    sort(crystal.begin(), crystal.end(), compair);
    sort(c, c + k);
    priority_queue<int> q;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && crystal[j].first <= c[i])
        {
            q.push(crystal[j].second);
            j++;
        }

        if (q.empty())
            continue;
        answer += q.top();
        q.pop();
    }
    cout << answer;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// vector<pair<int, int>> crystal; // 무게, 가격
// priority_queue<int> pq;
// multiset<int> bag; // 정렬
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     long long answer = 0;
//     int n, k, c1, c2;

//     cin >> n >> k;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> c1 >> c2;
//         crystal.push_back({c1, c2});
//         // cout << c1 << c2 << '\n';
//     }

//     for (int i = 0; i < k; i++)
//     {
//         cin >> c1;
//         bag.insert(c1);
//         // cout << c1 << '\n';
//     }
//     sort(crystal.begin(), crystal.end()); // 무게순으로 정렬

//     int index = 0;
//     for (auto it = bag.begin(); it != bag.end(); it++)
//     {
//         while (index < n && crystal[index].first <= *it) // n : 보석 개수
//         {
//             pq.push(crystal[index].second); // price
//             index++;
//         }
//         if (pq.empty())
//             continue;
//         answer += pq.top();
//         pq.pop();
//     }
//     cout<< answer<<'\n';

//     return 0;
// }