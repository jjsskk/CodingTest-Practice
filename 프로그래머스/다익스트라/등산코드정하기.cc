#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> ad[200001];
vector<int> answer;
bool summits_check[50001] = {
    false,
};
int intensity[50001];
// 우선순위 큐로 하든 그냥 큐로 하든 통과임 ( 경로안에서의 최소(최단거리)를 찾는게 아니고 경로끼리의 최소 값을 찾는거니까)
//  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // integritey, 산봉우리
queue<pair<int, int>> pq; // integritey, 산봉우리
vector<pair<int, int>> record;
void bfs(vector<int> &gates)
{
    memset(intensity, -1, sizeof(intensity));

    for (int i = 0; i < gates.size(); i++) // bfs 방식이니까 각각의 시작지점에서 순회경로가 모두 개별적으로 보장됨
    {
        pq.push({0, gates[i]});
        intensity[gates[i]] = 0;
    }

    while (!pq.empty())
    {
        // int cur_v = pq.top().second; // 산봉우리 번호
        // int cur_in = pq.top().first; // intensity
        int cur_v = pq.front().second; // 산봉우리 번호
        int cur_in = pq.front().first; // intensity
        pq.pop();

        if (cur_in > intensity[cur_v]) // 이거 없으면 testcase 21이 5000ms 나 걸려서 있어야할듯
            continue;

        if (summits_check[cur_v])
        {
            record.push_back({cur_in, cur_v});
            continue;
        }

        for (int i = 0; i < ad[cur_v].size(); i++)
        {
            int next_v = ad[cur_v][i].second;
            int next_cost = ad[cur_v][i].first;

            if (intensity[next_v] == -1 || max(cur_in, next_cost) < intensity[next_v]) // 처음 방문하는 주변 노드일 경우 intensity가 -1이기 때문에 특정경로에서 최대의 intensity를 찾는게 보장이 됨
            {
                intensity[next_v] = max(cur_in, next_cost);
                pq.push({intensity[next_v], next_v});
            }
        }
    }

    sort(record.begin(), record.end());
    // for(auto a : record)
    // {
    //     cout<<a.first<<" " << a.second<<endl;
    // }
    answer.push_back(record[0].second); // 산봉우리 번호
    answer.push_back(record[0].first);  // intensity
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{

    for (int i = 0; i < paths.size(); i++)
    {
        ad[paths[i][0]].push_back({paths[i][2], paths[i][1]});
        ad[paths[i][1]].push_back({paths[i][2], paths[i][0]});
    }

    for (int i = 0; i < summits.size(); i++)
    {
        summits_check[summits[i]] = true;
    }

    bfs(gates);

    return answer;
}