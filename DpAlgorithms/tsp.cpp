#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int memo[10][(1 << 10)];
int dist[10][10];

using namespace std;

int tsp(int pos, int mask, int n)
{
    if (mask == (1 << n) - 1)
    {
        return memo[pos][mask] = dist[pos][0];
    }

    int cant = (1 << 30);
    for (int i = 0; i < n; i++)
    {
        int a = (1 << i);
        if (((1 << i) & mask) == 0)
        {
            cant = min(cant, tsp(i, mask | (1 << i), n) + dist[pos][i]);
        }
    }

    return memo[pos][mask] = cant;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = -1;
        }
    }

    cout << tsp(0, 1, n) << "\n";

    return 0;
}