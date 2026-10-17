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

        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;

        int mn = a1;

        if (a2 < mn)
        {
            mn = a2;
        }

        if (a3 < mn)
        {
            mn = a3;
        }

        int ans = n - mn;
        cout << ans << endl;
    }

    return 0;
}