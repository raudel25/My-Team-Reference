#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = max(ans, sum);

        if (sum < 0)
            sum = 0;
    }

    cout << ans << "\n";

    return 0;
}