#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
int solution(vector<vector<int>> targets)
{
    int answer = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sort(targets.begin(), targets.end(), compare);

    int low_end = 0;
    int size = targets.size();
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        low_end = targets[i][1];

        for (j = i + 1; j < size; j++)
        {
            if (targets[j][0] >= low_end)
            {

                answer++;
                i = j - 1;
                break;
            }

            if (low_end > targets[j][1])
                low_end = targets[j][1];
        }
        i = j - 1; // 중요!!!!!!!!1
    }

    return answer;
}