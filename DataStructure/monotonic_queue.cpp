#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

using namespace std;

class MonotonicQueue
{
private:
    deque<pii> q;
    int head;
    int tail;
    int _size;

public:
    void MonoTonicQueue()
    {
        head = 0;
        tail = 0;
        _size = 0;
    }

    void pop()
    {
        if (q.front().second == head)
            q.pop_front();

        head++;
        _size--;
    }

    void push(int a)
    {
        while (!q.empty() && q.back().first >= a)
            q.pop_back();

        q.push_back({a, tail++});
        _size++;
    }

    bool empty() { return _size == 0; }

    int size() { return _size; }

    int min() { return q.front().first; }
};

void solve()
{
}

int32_t main()
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