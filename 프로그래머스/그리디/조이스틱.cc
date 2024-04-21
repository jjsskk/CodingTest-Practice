#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string name)
{
    int answer = 0;

    int alpha_move[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int min_move = name.size() - 1;
    int n = name.length();
    for (int i = 0; i < n; i++)
    {
        answer += alpha_move[name[i] - 'A'];

        int x = i;
        int y = x + 1;
        while (n > y && name[y] == 'A')
            y++;
        int side = min(x + x + n - y, n - y + n - y + x);
        min_move = min(min_move, side);
    }
    answer += min_move;

    return answer;
}