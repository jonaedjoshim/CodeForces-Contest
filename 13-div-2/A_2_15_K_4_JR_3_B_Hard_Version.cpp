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

        long long cnt[25];
        for (int i = 0; i < 25; i++)
        {
            cnt[i] = 0;
        }

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
            total += (1LL << x);
        }

        long long lim = total / 2;
        long long s = 0;

        for (int k = 24; k >= 0; k--)
        {
            long long can = (lim - s) >> k;
            long long take = min(cnt[k], can);
            s += take << k;
        }

        long long ans = s * (total - s);
        cout << ans << '\n';
    }

    return 0;
}