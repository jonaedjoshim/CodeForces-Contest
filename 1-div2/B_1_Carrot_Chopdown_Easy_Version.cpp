#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<long long> freq(m + 2, 0);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            freq[a]++;
        }

        vector<long long> suffix_sum(m + 2, 0);

        for (int x = m - 1; x >= 0; x--)
        {
            suffix_sum[x] = suffix_sum[x + 1] + freq[x + 1];
        }

        long long answer = 0;

        for (int x = 1; x <= m; x++)
        {
            long long count = freq[x] + suffix_sum[x];

            if (2 * x <= m)
            {
                count = count + freq[2 * x];
            }

            if (count > answer)
            {
                answer = count;
            }
        }

        cout << answer << endl;
    }

    return 0;
}