#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int memo_change[1000];
int memo_wsa[100][1000];
int coins[100];

using namespace std;

int change(int value, int n)
{
    if (value == 0)
        return 0;

    if (memo_change[value] != -1)
        return memo_change[value];

    int cant = (1 << 30);

    for (int i = 0; i < n; i++)
    {
        if (value >= coins[i])
        {
            cant = min(change(value - coins[i], n) + 1, cant);
        }
    }

    return memo_change[value] = cant;
}

int wsa(int type, int value, int n)
{
    if (type == n)
        return 0;

    if (value == 0)
        return 1;

    if (memo_wsa[type][value] != -1)
        return memo_wsa[type][value];

    int cant = wsa(type + 1, value, n);

    if (value >= coins[type])
    {
        cant += wsa(type, value - coins[type], n);
    }

    return memo_wsa[type][value] = cant;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m + 1; i++)
    {
        memo_change[i] = -1;
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m + 1; i++)
        {
            memo_wsa[j][i] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << change(m, n) << "\n";
    cout << wsa(0, m, n) << "\n";

    return 0;
}