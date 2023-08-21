#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

using namespace std;

// begin
class SuffixArray
{

public:
    SuffixArray(string s)
    {
        n = s.size();
        t = (char *)malloc(sizeof(char) * (n + 1));
        s_value = s + "$";

        for (int i = 0; i < n; i++)
            t[i] = s[i];
        t[n++] = '$';
        t[n] = 0;

        ra.assign(n, 0);
        sa.assign(n, 0);
        temp_ra.assign(n, 0);
        temp_sa.assign(n, 0);

        construct_sa();
    }

    int size() { return n; }

    int get_int(int i) { return sa[i]; }

    string get_str(int i) { return s_value.substr(sa[i], n - sa[i] - 1); }

private:
    char *t;
    string s_value;
    int n;

    vi ra;
    vi sa;
    vi c;
    vi temp_ra;
    vi temp_sa;

    void counting_sort(int k)
    {
        int sum = 0;
        int maxi = max((int)300, n);

        c.assign(maxi, 0);

        for (int i = 0; i < n; i++)
            c[i + k < n ? ra[i + k] : 0]++;

        for (int i = 0; i < maxi; i++)
        {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }

        for (int i = 0; i < n; i++)
            temp_sa[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];

        for (int i = 0; i < n; i++)
            sa[i] = temp_sa[i];
    }

    void construct_sa()
    {
        int k, r;

        for (int i = 0; i < n; i++)
        {
            ra[i] = t[i];
            sa[i] = i;
        }

        for (k = 1; k < n; k <<= 1)
        {
            counting_sort(k);
            counting_sort(0);

            temp_ra[sa[0]] = r = 0;

            for (int i = 1; i < n; i++)
                temp_ra[sa[i]] = (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k]) ? r : ++r;

            for (int i = 0; i < n; i++)
                ra[i] = temp_ra[i];

            if (ra[sa[n - 1]] == n - 1)
                break;
        }
    }

    
};
// end;

void solve()
{
    string s;
    cin >> s;

    SuffixArray suffix(s);

    for (int i = 0; i < suffix.size(); i++)
        cout << suffix.get_int(i) << " ";
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
   
    return 0;
}