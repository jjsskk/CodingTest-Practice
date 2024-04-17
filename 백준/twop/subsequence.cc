#include <bits/stdc++.h>

using namespace std;

int n;
long long s;
long long sum = 0;
int answer = 100001;
int main()
{
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // queue<int> q;
    // for (int i = 0; i < n; i++)
    // {
    //     sum += (long long)a[i];
    //     q.push(a[i]);
    //     while (sum >= s)
    //     {
    //         answer = min(answer, (int)q.size());
    //         sum -= q.front();
    //         q.pop();
    //     }
    // }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (long long)a[i];
        while (sum >= s && j < n)
        {
            answer = min(answer, i-j+1);
            sum -= (long long)a[j];
            j++;
        }

    }

    if (answer == 100001)
        answer = 0;
    cout << answer;
    return 0;
}
