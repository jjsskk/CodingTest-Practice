#include <bits/stdc++.h>

using namespace std;

// 1, 생성한 접점 찾기 -> 들어오는 간선 x
// 2. 생성한 접점을 이용해 전체 travel
map<int, vector<int>> ad;

int dfs(int cur_node)
{
    int temp_node = cur_node;

    while (!ad[temp_node].empty())
    {
        if (ad[temp_node].size() >= 2)
            return 3; // 이게 먼저 체크 안되면 오답 나옴 -> case2 8번 잘생각해봐
        if (ad[temp_node][0] == cur_node)
            return 1;

        temp_node = ad[temp_node][0];
    }

    return 2;
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> check(1000001, 0);
    vector<int> answer(4, 0);
    int node = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if (ad.end() == ad.find(edges[i][0]))
            ad.insert({edges[i][0], vector<int>()});
        ad[edges[i][0]].push_back(edges[i][1]);
        check[edges[i][1]]++;
    }

    // 정첨 찾기
    for (int i = 1; i < check.size(); i++)
    {
        if (check[i] == 0 && ad[i].size() >= 2)
        {
            node = i;
            answer[0] = (node);
            break;
        }
    }
    // cout<<node;
    // travel dfs
    for (int i = 0; i < ad[node].size(); i++)
    {
        answer[dfs(ad[node][i])]++;
    }

    return answer;
}