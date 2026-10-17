#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int smallest_prime[MAX + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= MAX; i++)
    {
        if (smallest_prime[i] == 0)
        {
            smallest_prime[i] = i;
            if ((long long)i * i <= MAX)
            {
                for (int j = i * i; j <= MAX; j += i)
                {
                    if (smallest_prime[j] == 0)
                    {
                        smallest_prime[j] = i;
                    }
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<long long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (i <= k)
            {
                dp[i] = 0;
            }
            else
            {
                long long best = 4e18;
                int x = i;
                while (x > 1)
                {
                    int p = smallest_prime[x];
                    long long current = 1 + (long long)p * dp[i / p];
                    if (current < best)
                    {
                        best = current;
                    }
                    while (x % p == 0)
                    {
                        x /= p;
                    }
                }
                dp[i] = best;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dp[a[i]];
        }

        cout << ans << endl;
    }

    return 0;
}