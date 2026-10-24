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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> cnt(n + 2, 0);
        for (int i = 0; i < n; i++)
        {
            cnt[a[i]]++;
        }

        vector<int> pref(n + 2, 0);
        pref[0] = cnt[0];
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + cnt[i];
        }

        int mex = 0;
        int used = 0;

        for (int x = 0; x <= n; x++)
        {
            if (cnt[x] == 0)
            {
                break;
            }

            if (pref[x] - used >= k)
            {
                used += k;
                mex = x + 1;
            }
            else
            {
                break;
            }
        }

        cout << mex << '\n';
    }

    return 0;
}