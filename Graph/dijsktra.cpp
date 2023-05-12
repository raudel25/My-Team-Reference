#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

int infinite = (int)1e9;

// O(V^2)
vector<int> dijkstra1(int V, vector<vector<int>> adj[], int S)
{
    vector<int> d;

    d.assign(V, infinite);
    d[S] = 0;

    vector<bool> mask;

    mask.assign(V, false);

    for (int i = 0; i < V; i++)
    {
        int m = infinite;
        int act = -1;

        for (int j = 0; j < V; j++)
        {
            if (mask[j])
                continue;

            if (m > d[j])
            {
                m = d[j];
                act = j;
            }
        }

        for (int j = 0; j < adj[act].size(); j++)
        {
            if (d[act] + adj[act][j][1] < d[adj[act][j][0]])
            {
                d[adj[act][j][0]] = d[act] + adj[act][j][1];
            }
        }

        mask[act] = true;
    }

    return d;
}

// O((V+E)log(E))
vector<int> dijkstra2(int V, vector<vector<int>> adj[], int S)
{
    vector<int> d;

    d.assign(V, infinite);
    d[S] = 0;

    vector<bool> mask;

    priority_queue<pair<int, int>> q;
    q.push({d[S], S});

    mask.assign(V, false);

    for (int i = 0; i < V; i++)
    {
        int act = -1;
        int m = infinite;

        while (act == -1)
        {
            int top = q.top().second;
            int m = abs(q.top().first);
            q.pop();

            if (!mask[top])
                act = top;
        }

        for (int j = 0; j < adj[act].size(); j++)
        {
            if (d[act] + adj[act][j][1] < d[adj[act][j][0]])
            {
                d[adj[act][j][0]] = d[act] + adj[act][j][1];
                q.push({-d[adj[act][j][0]], adj[act][j][0]});
            }
        }

        mask[act] = true;
    }

    return d;
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}