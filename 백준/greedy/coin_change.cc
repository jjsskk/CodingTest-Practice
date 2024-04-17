#include <bits/stdc++.h>

using namespace std;

int main()
{
    int price, change;
    cin >> price;
    int count = 0;
    change = 1000 - price;
    count += (change / 500);
    change = change % 500;

    count += (change / 100);
    change = change % 100;

    count += (change / 50);
    change = change % 50;

    count += (change / 10);
    change = change % 10;

    count += (change / 5);
    change = change % 5;

    count += (change / 1);
    change = change % 1;

    cout << count;

    return 0;
}


