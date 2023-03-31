#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

vector<bool> visited;
vector<int> t;
vector<int> low;
vector<bool> art;

void dfs(vector<int> adj[], int n, int p, int q)
{
    t[n] = q;
    low[n] = q++;
    visited[n] = true;

    int j = 0;

    for (int i = 0; i < adj[n].size(); i++)
    {
        if (!visited[adj[n][i]])
        {
            dfs(adj, adj[n][i], n, q);
            low[n] = min(low[adj[n][i]], low[n]);
            j++;

            if (low[adj[n][i]] >= t[n] && p != -1)
            {
                art[n] = true;
            }
        }
        else if (adj[n][i] != p)
        {
            low[n] = min(t[adj[n][i]], low[n]);
        }
    }

    if (p == -1)
    {
        art[n] = j >= 2;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    visited.assign(V, false);
    t.assign(V, -1);
    low.assign(V, -1);
    art.assign(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, -1, 1);
        }
    }

    vector<int> resp;

    for (int i = 0; i < V; i++)
    {
        if (art[i])
            resp.push_back(i);
    }
    if (resp.size() == 0)
        resp.push_back(-1);

    return resp;
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