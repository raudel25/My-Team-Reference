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

    int lsi[n];
    int l[n + 1];

    lsi[0] = 1;
    l[1] = a[0];

    for (int i = 1; i < n; i++)
    {
        int ind = lsi[i - 1];
        if (l[1] < a[i] && a[i] < l[lsi[i - 1]])
        {
            int left = 1;
            int right = lsi[i - 1];

            while (right - left >= 2)
            {
                int m = (left + right) / 2;

                if (l[m] < a[i])
                    left = m;
                else
                    right = m;
            }

            ind = left;
        }

        if (a[i] <= l[1] || a[i] == l[lsi[i - 1]])
            lsi[i] = lsi[i - 1];
        else
        {
            if (lsi[i - 1] >= ind + 1)
            {
                l[ind + 1] = min(l[ind + 1], a[i]);
                lsi[i] = lsi[i - 1];
            }
            else
            {
                l[ind + 1] = a[i];
                lsi[i] = ind + 1;
            }
        }
    }

    cout << lsi[n - 1] << "\n";

    return 0;
}