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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long center = a[n / 2];
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > center)
            {
                ans += a[i] - center;
            }
            else
            {
                ans += center - a[i];
            }
        }

        cout << ans << ' ' << a[n - 1] - a[0] << '\n';
    }

    return 0;
}