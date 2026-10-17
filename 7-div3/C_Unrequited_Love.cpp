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

        map<long long, long long> freq;
        long long ans = 0;

        for (int i = 0; i + 4 < n; i++)
        {
            long long value = a[i] + a[i + 2] - a[i + 4];

            ans += freq[value];

            if (i >= 2)
            {
                long long prev_value = a[i - 2] + a[i] - a[i + 2];

                if (prev_value == value)
                {
                    ans--;
                }
            }

            if (i >= 4)
            {
                long long prev_value = a[i - 4] + a[i - 2] - a[i];

                if (prev_value == value)
                {
                    ans--;
                }
            }

            freq[value]++;
        }

        cout << ans << endl;
    }

    return 0;
}