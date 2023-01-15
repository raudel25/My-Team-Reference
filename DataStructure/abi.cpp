#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

class Abi
{

private:
    vll p;
    int _size;

    int ls_one(int i) { return i & (-i); }

public:
    Abi(int n)
    {
        _size = n;
        p.assign(n + 1, 0);
    }

    ll rsq(int k)
    {
        ll sum = 0;

        for (int i = k; i > 0; i -= ls_one(i))
        {
            sum += p[i];
        }

        return sum;
    }

    ll sum(int a, int b) { return rsq(b) - rsq(a - 1); }

    void adjust_sum(int k, int v)
    {
        for (int i = k; i < p.size(); i += ls_one(i))
            p[i] += v;
    }

    int size()
    {
        return _size;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}