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
        int n, m;
        cin >> n >> m;

        string p, q;
        cin >> p >> q;

        int cnt[26] = {0};

        for (int i = 0; i < n; i++)
        {
            cnt[p[i] - 'a']++;
        }

        for (int i = 0; i < m; i++)
        {
            cnt[q[i] - 'a']--;
        }

        int flag = 1;

        if (cnt['s' - 'a'] != 1 || cnt['i' - 'a'] != 1 || cnt['x' - 'a'] != 1)
        {
            flag = 0;
        }

        for (int i = 0; i < 26; i++)
        {
            if (i == 's' - 'a' || i == 'i' - 'a' || i == 'x' - 'a')
            {
                continue;
            }
            if (cnt[i] != 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}