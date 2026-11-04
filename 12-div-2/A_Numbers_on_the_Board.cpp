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
        int l, r;
        cin >> l >> r;

        int total = r - l + 1;
        int kept = 1;

        if (l <= 0 && r >= 0)
        {
            int m = min(-l, r);
            kept = 2 * m + 1;
            if (total > kept)
            {
                kept++;
            }
        }

        cout << total - kept << '\n';
    }

    return 0;
}