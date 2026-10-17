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
        long long x, y, k;
        cin >> x >> y >> k;

        long long d = y - x;
        long long ans = 0;
        long long i = 0;

        while (i < k && x + i <= d)
        {
            ans += d % (x + i);
            i++;
        }

        ans += (k - i) * d;

        cout << ans << endl;
    }

    return 0;
}