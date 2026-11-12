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
        string s;
        cin >> n >> s;

        int diff[27];
        for (int i = 0; i < 27; i++)
        {
            diff[i] = 0;
        }

        for (int i = 0; i < n / 2; i++)
        {
            int leftChar = s[i] - 'a';
            int rightChar = s[n - 1 - i] - 'a';

            if (leftChar > rightChar)
            {
                swap(leftChar, rightChar);
            }

            if (leftChar != rightChar)
            {
                diff[leftChar + 1]++;
                diff[rightChar + 1]--;
            }
        }

        int ans = 0;
        int activeOps = 0;

        for (int i = 0; i < 26; i++)
        {
            activeOps += diff[i];
            if (activeOps > 0)
            {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}