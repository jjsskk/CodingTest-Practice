#include <bits/stdc++.h>

using namespace std;

int a[200001];
int n, k;
int fre[100001];
int len = 0;
int answer = 0;
int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    memset(fre, 0, sizeof(fre));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && fre[a[j]] < k)
        {
            fre[a[j]]++;
            answer = max(answer, j - i + 1);
            j++;
        }
        if (j == n)
            break;
        fre[a[i]]--;
    }
    cout << answer;
    return 0;
}