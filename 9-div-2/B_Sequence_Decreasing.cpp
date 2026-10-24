#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long min_val = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            min_val = min(min_val, x);
        }

        if (min_val <= n - 1)
        {
            cout << n << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}