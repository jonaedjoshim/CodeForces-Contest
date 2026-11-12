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

        int cur = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int need = 0;
            if (s[i] == 'B')
            {
                need = 1;
            }

            if (cur != need)
            {
                ans++;
            }

            cur = 1 - need;
        }

        cout << ans << '\n';
    }

    return 0;
}