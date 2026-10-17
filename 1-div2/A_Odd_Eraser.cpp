#include <bits/stdc++.h>
using namespace std;

int main()
{
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

        long long ans;

        if (n == 1)
        {
            ans = a[0];
        }
        else
        {
            ans = __gcd(a[0], a[n - 1]);
        }

        cout << ans << endl;
    }

    return 0;
}