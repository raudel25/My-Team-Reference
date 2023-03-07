#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

int memo[100][100];
int w[100];
int v[100];

using namespace std;

int val(int id, int m, int n)
{
    if (id == n)
        return 0;
    if (m == 0)
        return 0;
    if (memo[id][m] != -1)
        return memo[id][m];
    if (m < w[id])
        return memo[id][m] = val(id + 1, m, n);

    return memo[id][m] = max(val(id + 1, m - w[id], n) + v[id], val(id + 1, m, n));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + 1; j++)
            memo[i][j] = -1;
    }

    cout << val(0, m, n) << "\n";

    return 0;
}