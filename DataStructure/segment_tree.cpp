#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

struct node
{

private:
    int _valor;

public:
    node(int n)
    {
        _valor = n;
    }

    int get_valor() { return _valor; }
};

class SegmentTree
{
private:
    vector<node> _a;
    vector<int> _st;
    vector<long long> _sum;
    int n;

    int left(int p) { return p << 1; };

    int right(int p) { return (p << 1) + 1; }

    void build(int p, int l, int r)
    {
        if (l == r)
        {
            _st[p] = l;
            _sum[p] = _a[l].get_valor();
        }
        else
        {
            build(left(p), l, (l + r) / 2);
            build(right(p), (l + r) / 2 + 1, r);

            int p1 = _st[left(p)];
            int p2 = _st[right(p)];

            _st[p] = (_a[p1].get_valor() <= _a[p2].get_valor()) ? p1 : p2;
            _sum[p] = _sum[left(p)] + _sum[right(p)];
        }
    }

    void set(int p, int l, int r, int i, node v)
    {
        if (l == r)
        {
            _sum[p] = v.get_valor();
            _a[l] = v;
        }
        else
        {
            if (i <= (l + r) / 2)
                set(left(p), l, (l + r) / 2, i, v);
            else
                set(right(p), (l + r) / 2 + 1, r, i, v);

            int p1 = _st[left(p)];
            int p2 = _st[right(p)];

            _st[p] = (_a[p1].get_valor() <= _a[p2].get_valor()) ? p1 : p2;
            _sum[p] = _sum[left(p)] + _sum[right(p)];
        }
    }

    long long sum(int p, int l, int r, int i, int j)
    {
        if (i > r || j < l)
            return 0;
        if (i <= l && r <= j)
            return _sum[p];

        long long p1 = sum(left(p), l, (l + r) / 2, i, j);
        long long p2 = sum(right(p), (l + r) / 2 + 1, r, i, j);

        return p1 + p2;
    }

    int rmq(int p, int l, int r, int i, int j)
    {
        if (i > r || j < l)
            return -1;
        if (i <= l && r <= j)
            return _st[p];

        int p1 = rmq(left(p), l, (l + r) / 2, i, j);
        int p2 = rmq(right(p), (l + r) / 2 + 1, r, i, j);

        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;

        return (_a[p1].get_valor() <= _a[p2].get_valor()) ? p1 : p2;
    }

public:
    SegmentTree(vector<node> &a)
    {
        _a = a;
        n = a.size();
        _st.assign(4 * n, 0);
        _sum.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

    long long sum(int i, int j) { return sum(1, 0, n - 1, i, j); }

    void set(int i, node v) { set(1, 0, n - 1, i, v); }

    node get(int i) { return _a[i]; }
};

int main()
{
    ios_base::sync_with_stdio();
    cin.tie();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
    }

    return 0;
}
