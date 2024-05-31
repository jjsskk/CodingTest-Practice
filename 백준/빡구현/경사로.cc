#include <bits/stdc++.h>

using namespace std;

int n, l;
int a[101][101];
int b[101][101];
int cnt = 0; // 길 개수

void check(int road[][101])
{
    for (int i = 0; i < n; i++)
    {
        bool possible = true;
        bool slope[101] = {false};
        for (int j = 0; j < n - 1; j++)
        {

            // 1. 높이 간격이 1 보다 클떄
            if (abs(road[i][j] - road[i][j + 1]) > 1)
            {
                possible = false;
                break;
            }

            // 2. 다음 블록이 높이가 1 작을떄
            if (road[i][j] == road[i][j + 1] + 1)
            {
                int height = road[i][j + 1];
                for (int k = j + 2; k < j + 1 + l; k++)
                {
                    if (k >= n || road[i][k] != height)
                    {
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                    break;
                else
                    slope[j + l] = true;
            }

            // 3. 다음 블록이 높이가 1 클때
            if (road[i][j] == road[i][j + 1] - 1)
            {
                int height = road[i][j];
                for (int k = j; k > j - l; k--)
                {

                    if (k < 0 || road[i][k] != height || slope[k])
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if (!possible)
                break;
        }
        if (possible)
            cnt++;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l;
    int c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            a[i][j] = c;
            b[j][i] = c;
        }

    check(a);
    check(b);
    cout << cnt;
    return 0;
}