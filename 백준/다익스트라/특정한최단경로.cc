#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

vector<pair<int, int>> a[801];
int n, e, v1, v2;

int d[801];
void initialize()
{
    for (int i = 0; i <= n; i++)
        d[i] = INF;
}
int bfs(int start, int end)
{
    initialize();
    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cur_node = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();
        for (int i = 0; i < a[cur_node].size(); i++)
        {

            int next_node = a[cur_node][i].first;
            int next_dis = a[cur_node][i].second + dis;
            if (next_dis < d[next_node])
            {
                d[next_node] = next_dis;
                pq.push({-next_dis, next_node});
            }
        }
    }
    return d[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    int b1, b2, c;
    for (int i = 0; i < e; i++)
    {
        cin >> b1 >> b2 >> c;
        a[b1].push_back({b2, c});
        a[b2].push_back({b1, c});
    }
    cin >> v1 >> v2;
    int answer = -1;
    int dis1, dis2;
    if (bfs(1, v1) == INF || bfs(v1, v2) == INF || bfs(v2, n) == INF)
        dis1 = INF;
    else
        dis1 = bfs(1, v1) + bfs(v1, v2) + bfs(v2, n);
    if (bfs(1, v2) == INF || bfs(v2, v1) == INF || bfs(v1, n) == INF)
        dis2 = INF;
    else
        dis2 = bfs(1, v2) + bfs(v2, v1) + bfs(v1, n);

    if (dis1 != INF || dis2 != INF)
        answer = min(dis1, dis2);
    cout << answer;
    return 0;
}
