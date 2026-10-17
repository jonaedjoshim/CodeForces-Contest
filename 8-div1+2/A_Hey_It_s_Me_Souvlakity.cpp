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

        string s;
        cin >> s;

        int total = 0;
        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                total++;
                if (first == -1)
                {
                    first = i;
                }
                last = i;
            }
        }

        int ans = 0;

        if (total == 1)
        {
            ans = 0;
        }
        else if (total == 2)
        {
            ans = 1;
        }
        else
        {
            ans = last - first;
        }

        cout << ans << '\n';
    }

    return 0;
}