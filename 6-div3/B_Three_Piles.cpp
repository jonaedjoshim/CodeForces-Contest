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
        long long a, b, c;
        cin >> a >> b >> c;

        long long d = a - b;
        long long ans1 = d;
        if (ans1 < 0)
        {
            ans1 = -ans1;
        }

        long long ans2 = c + d;
        if (ans2 < 0)
        {
            ans2 = -ans2;
        }

        long long ans = ans1;
        if (ans2 > ans)
        {
            ans = ans2;
        }

        cout << ans << endl;
    }

    return 0;
}