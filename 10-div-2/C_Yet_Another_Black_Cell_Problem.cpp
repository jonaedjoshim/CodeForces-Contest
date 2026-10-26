#include <bits/stdc++.h>
using namespace std;

bool check(long long k, vector<long long> &a, int x)
{
    int n = a.size();
    vector<int> bad;

    for (int i = 0; i < n; i++)
    {
        bool left_bad = (i == 0) || (a[i] - a[i - 1] > k);
        bool right_bad = (i == n - 1) || (a[i + 1] - a[i] > k);

        if (left_bad && right_bad)
        {
            bad.push_back(i);
        }
    }

    int need = 0;
    int i = 0;

    while (i < (int)bad.size())
    {
        if (i + 1 < (int)bad.size() && a[bad[i + 1]] - a[bad[i]] <= 2 * k)
        {
            need++;
            i += 2;
        }
        else
        {
            need++;
            i++;
        }
    }

    return need <= x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long low = 1;
        long long high = 1000000000;
        long long ans = high;

        while (low <= high)
        {
            long long mid = (low + high) / 2;

            if (check(mid, a, x))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}