#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2);

    unordered_map<string, int> counting;
    set<string> unique(gems.begin(), gems.end());
    int start = 0, end = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        counting[gems[i]]++;
        if (counting.size() == unique.size())
            break;
        end++;
    }

    answer[0] = start + 1;
    answer[1] = end + 1;

    int min = end - start;

    while (gems.size() > end)
    {
        string a = gems[start];
        start++;

        counting[a]--;

        if (counting[a] == 0)
        {
            end++;
            while (gems.size() > end)
            {
                counting[gems[end]]++; //  핵심!!
                if (a == gems[end])
                    break;
                end++;
            }

            if (end == gems.size())
                break;
        }

        if (min > end - start)
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
            min = end - start;
        }
    }

    return answer;
}