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

        string s;
        cin >> s;

        if (s[0] == '1')
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }

        else
        {
            int total_zeros = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    total_zeros++;
                }
            }

            int ans = total_zeros;
            int ones = 0;
            int zeros = total_zeros;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    ones++;
                }
                else
                {
                    zeros--;
                }

                int current = ones + zeros;
                if (current < ans)
                {
                    ans = current;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}