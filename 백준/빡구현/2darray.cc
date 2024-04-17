#include <bits/stdc++.h>
using namespace std;
int r, c, k;
int n = 3, m = 3;
int answer = 0;
int a[100][100];
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

void go()
{
    int first, second;
    while (true)
    {
        if (a[r - 1][c - 1] == k)
            return;
        if (answer == 100)
        {
            answer = -1;
            return;
        }
        if (n >= m)
        {
            first = n;
            second = m;
        }
        else
        {
            first = m;
            second = n;
        }

        vector<int> l(first);
        for (int i = 0; i < first; i++)
        {
            vector<pair<int, int>> array;
            int fre[101];
            memset(fre, 0, sizeof(fre));

            for (int j = 0; j < second; j++)
            {
                if (n >= m)
                    fre[a[i][j]]++;
                else
                    fre[a[j][i]]++;
            }
            for (int j = 1; j < 101; j++)
            {
                if (fre[j] == 0)
                    continue;
                array.push_back({fre[j], j});
            }
            sort(array.begin(), array.end(), compare);

            for (int j = 0; j < array.size() && j < 50; j++)
            {
                if (n >= m)
                {
                    a[i][2 * j] = array[j].second;
                    a[i][2 * j + 1] = array[j].first;
                }
                else
                {
                    a[2 * j][i] = array[j].second;
                    a[2 * j + 1][i] = array[j].first;
                }
            }
            // cout<<"here"<<'\n';

            l[i] = array.size() >= 50 ? 100 : array.size() * 2;
        }

        second = *max_element(l.begin(), l.end());
        for (int i = 0; i < first; i++)
            for (int j = l[i]; j < second; j++)
            {
                if (n >= m)
                    a[i][j] = 0;
                else
                    a[j][i] = 0;
            }

        if (n >= m)
            m = second;
        else
            n = second;
        answer++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c >> k;

    // cout<<r<<c<<k<<'\n';
    memset(a, 0, sizeof(a));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    go();
    cout << answer;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define num first // 숫자
// #define f second  // 빈도수
// int board[101][101];
// int freq[101]; // 빈도수 배열
// bool cmp(pair<int, int> n1, pair<int, int> n2)
// { // 행 또는 열의 정렬 기준
//     if (n1.f == n2.f)
//         return n1.num < n2.num; // 빈도수가 같으면 수가 커지는 순으로
//     else
//         return n1.f < n2.f; // 빈도수가 커지는 순으로
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int r, c, k;
//     cin >> r >> c >> k;
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             cin >> board[i][j];    //  배열 입력 받음
//     int row = 3, col = 3, sec = 0; // 행/열의 개수
//     while (true)
//     {
//         if (board[r - 1][c - 1] == k)
//             break; // A[r][c]의 값이 k인 경우 중단
//         if (sec == 100)
//         {
//             sec = -1;
//             break;
//         } // 100초가 지나도 A[r][c] != k이면, 중단
//         int first, second;
//         if (row >= col)
//         {
//             first = row;
//             second = col;
//         }
//         else
//         {
//             first = col;
//             second = row;
//         }
//         vector<int> l(first);
//         for (int i = 0; i < first; i++)
//         {                              // 각 행 또는 열에 대해 연산을 수행
//             fill(freq, freq + 101, 0); // 빈도수 배열을 0으로 초기화
//             vector<pair<int, int>> sf; // {수, 빈도수}를 저장하기 위한 벡터
//             for (int j = 0; j < second; j++)
//                 if (row >= col)
//                     freq[board[i][j]]++; // 빈도수 증가
//                 else
//                     freq[board[j][i]]++;
//             for (int j = 1; j <= 100; j++)
//                 if (freq[j] != 0)
//                     sf.push_back({j, freq[j]}); // 각각의 {수, 빈도수}를 벡터에 저장 (수/빈도수 0은 무시)
//             sort(sf.begin(), sf.end(), cmp);    // {수, 빈도수}의 벡터를 정렬 기준에 따라 정렬
//             for (int j = 0; j < sf.size() && j < 50; j++)
//                 if (row >= col)
//                 {
//                     board[i][j * 2] = sf[j].num;
//                     board[i][j * 2 + 1] = sf[j].f;
//                 } // 벡터를 정렬하여 다시 행 또는 열에 기록 (최대 100개)
//                 else
//                 {
//                     board[j * 2][i] = sf[j].num;
//                     board[j * 2 + 1][i] = sf[j].f;
//                 }
//             l[i] = (sf.size() >= 50) ? 100 : sf.size() * 2; // 정렬된 행 또는 열의 크기, 크기가 100을 넘어가는 경우 나머지는 버림
//         }
//         second = *max_element(l.begin(), l.end()); // 행 또는 열의 최대 크기
//         for (int i = 0; i < first; i++)            // 가장 큰 행 또는 열의 크기에 맞춰 모든 행 또는 열의 나머지 부분에 0을 채움
//             for (int j = l[i]; j < second; j++)
//                 if (row >= col)
//                     board[i][j] = 0;
//                 else
//                     board[j][i] = 0;
//         if (row >= col)
//         {
//             col = second;
//         }
//         else
//         {
//             row = second;
//         } // 업데이트 된 행 또는 열의 크기를 다시 row 또는 col에 저장
//         sec++;
//     }
//     cout << sec;
// }
