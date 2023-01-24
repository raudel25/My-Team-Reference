#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int memo[1000];
int coins[100];

using namespace std;

int change(int value, int n)
{
    if (value == 0)
        return 0;

    int cant = (1 << 30);

    for (int i = 0; i < n; i++)
    {
        if (cant >= coins[i])
        {
            cant = min(change(value - coins[i], n) + 1, cant);
        }
    }

    return memo[value] = cant;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << change(m, n) << "\n";

    return 0;
}