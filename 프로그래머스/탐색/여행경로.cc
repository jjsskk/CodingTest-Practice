#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int total_cnt = 0;
map<string, multiset<string>> ad;
map<string, vector<bool>> visited;
vector<string> answer;
vector<string> record;
bool check = false;

void dfs(string v, int count)
{
    if (!check)
    {

        if (count == total_cnt)
        {
            answer = record;
            check = true;
            return;
        }

        int i = 0;
        for (auto it = ad[v].begin(); it != ad[v].end(); it++)
        {
            if (visited[v][i])
            {
                i++;
                continue;
            }
            visited[v][i] = true;
            record.push_back(*it);
            dfs(*it, count + 1);
            record.pop_back();
            visited[v][i] = false;
            i++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{

    total_cnt = tickets.size() + 1;
    for (int i = 0; i < tickets.size(); i++)
    {

        if (ad.end() == ad.find(tickets[i][0]))
        {
            ad.insert({tickets[i][0], multiset<string>()});
            visited.insert({tickets[i][0], vector<bool>()});
        }
        ad[tickets[i][0]].insert(tickets[i][1]);
        visited[tickets[i][0]].push_back(false);
    }

    cout << total_cnt;
    record.push_back("ICN");
    dfs("ICN", 1);

    return answer;
}