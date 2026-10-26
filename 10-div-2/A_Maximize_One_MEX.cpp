#include <bits/stdc++.h>
using namespace std;

int get_kth(vector<int> a, int k)
{
    int n = a.size();
    vector<int> f(n);
    vector<int> seen(n + 2, 0);
    int mex = 0;

    for (int i = 0; i < n; i++)
    {
        seen[a[i]] = 1;
        while (seen[mex])
        {
            mex++;
        }
        f[i] = mex;
    }

    sort(f.begin(), f.end(), greater<int>());
    return f[k - 1];
}

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

        int original = get_kth(a, k);
        int best = original;
        int ans_i = -1;
        int ans_j = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(a[i], a[j]);

                int val = get_kth(a, k);

                if (val > best)
                {
                    best = val;
                    ans_i = i + 1;
                    ans_j = j + 1;
                }

                swap(a[i], a[j]);
            }
        }

        if (ans_i == -1)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << ans_i << ' ' << ans_j << '\n';
        }
    }

    return 0;
}