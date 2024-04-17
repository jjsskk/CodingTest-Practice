#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int n, m, x;
vector<pair<int, int>> a[1001];
int d[1001];

void bfs(int start)
{
    priority_queue<pair<int, int>> pq;

    d[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = -1 * pq.top().first;
        pq.pop();

        for (int i = 0; i < a[node].size(); i++)
        {
            int next_node = a[node][i].first;
            int next_dis = dis + a[node][i].second;
            // cout << d[next_node] << endl;
            if (next_dis < d[next_node])
            {
                d[next_node] = next_dis;

                pq.push({-1 * next_dis, next_node});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int answer = 0;
    cin >> n >> m >> x;
    int v1, v2, e;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> e;
        a[v1].push_back({v2, e});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            d[j] = INF;
        bfs(i);
        int dis1 = d[x];
        
        for (int j = 0; j < n + 1; j++)
            d[j] = INF;
        bfs(x);
        int dis2 = d[i];
        answer = max(answer, dis1 + dis2);
    }
    cout << answer;
    return 0;
}