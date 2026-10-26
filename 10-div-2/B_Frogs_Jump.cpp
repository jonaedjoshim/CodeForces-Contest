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

        string s1, s2;
        cin >> s1 >> s2;

        int total = 0;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] == 'f')
            {
                total++;
            }
            if (s2[i] == 'f')
            {
                total++;
            }
        }

        if (total % 2 == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }

    return 0;
}