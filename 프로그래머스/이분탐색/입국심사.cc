#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;

    sort(times.begin(), times.end());
    long long left = 1;                            // 1사람이 1분의 심사 걸릴때
    long long right = n * (long long)times.back(); // 가장 오래걸리는 심사위원에게 n명의 사람이 모두 심사를 받을때

    while (left <= right)
    {
        long long mid = (left + right) / 2; // 모든 사람이 입국심사를 받는데 걸리는 최소시간이 이분탐색의 탐색 대상!!

        long long num = 0;
        for (int i = 0; i < times.size(); i++)
        {
            num += (mid / (long long)times[i]); // mid라는 시간동안 각각의 심사위원들이 동시에 작업한다.
        }

        if (num >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else
            left = mid + 1;
    }

    return answer;
}