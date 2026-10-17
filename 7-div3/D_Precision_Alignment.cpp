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
        long long k;
        cin >> n >> k;

        vector<long long> a(n), b(n), c(n);
        long long low = 4e18;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];

            long long total = a[i] + b[i] + c[i];

            if (total < low)
            {
                low = total;
            }
        }

        long long high = low + k;

        while (low < high)
        {
            long long mid = low + (high - low + 1) / 2;

            long long need = 0;
            int flag = 1;

            for (int i = 0; i < n; i++)
            {
                long long total = a[i] + b[i] + c[i];

                if (total >= mid)
                {
                    continue;
                }

                if (a[i] == b[i] && b[i] == c[i])
                {
                    flag = 0;
                    break;
                }

                long long diff = mid - total;

                if (a[i] <= b[i] && b[i] <= c[i])
                {
                    long long p = b[i] - a[i];
                    long long q = c[i] - b[i];

                    diff += 2 * min(p, q) + 2;
                }

                need += diff;

                if (need > k)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1 && need <= k)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << low << '\n';
    }

    return 0;
}