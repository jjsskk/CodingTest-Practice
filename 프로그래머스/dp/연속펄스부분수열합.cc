#include <bits/stdc++.h>
// DP 문제
//  #include <cmath>
using namespace std;

vector<int> transform(vector<int> seq, int num)
{
    for (int i = 0; i < seq.size(); i++)
    {
        seq[i] *= num;
        num *= (-1);
    }

    return seq;
}

long long solution(vector<int> sequence)
{

    long long answer = -100000000;
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> seq1 = transform(sequence, 1);
    vector<int> seq2 = transform(sequence, -1);

    int size = sequence.size();
    long long dp1[size];
    long long dp2[size];

    dp1[0] = seq1[0];
    for (int i = 1; i < size; i++)
    {
        dp1[i] = max(dp1[i - 1] + (long long)seq1[i], (long long)seq1[i]);
        answer = max(answer, dp1[i]);
    }

    dp2[0] = seq2[0];
    for (int i = 1; i < size; i++)
    {
        dp2[i] = max(dp2[i - 1] + (long long)seq2[i], (long long)seq2[i]);
        answer = max(answer, dp2[i]);
    }

    if (size == 1)
    {
        answer = max((long long)dp1[0], answer);
        answer = max((long long)dp2[0], answer);
    }

    return answer;
}
