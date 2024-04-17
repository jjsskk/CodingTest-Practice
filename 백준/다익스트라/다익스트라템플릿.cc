#include <bits/stdc++.h>
// #define INFI 1001
using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> a[801];
int parent[801] = {
    -1,
};
int d[801] = {
    100000000,
};
void go(int start)
{
    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int distance = -1 * (pq.top().first);
        int node = pq.top().second;
        pq.pop();

        for (int i = 0; i < a[node].size(); i++)
        {

            int next_distance = d[node] + a[node][i].second;
            int next_node = a[node][i].first;
            if (d[next_node] > next_distance)
            {
                d[next_node] = next_distance;
                pq.push({-next_distance, next_node});
                parent[next_node] = node;
            }
        }
    }
}
int main()
{

    cin >> n >> e;
    int n1, n2, v;
    for (int i = 0; i < e; i++)
    {
        cin >> n1 >> n2 >> e;
        a[n1].push_back({n2, e});
        a[n2].push_back({n1, e});
    }
    cin >> v1 >> v2;
    go(1);
    return 0;
}