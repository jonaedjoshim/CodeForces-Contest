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

        int odd_count = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 != 0)
            {
                odd_count++;
            }
        }

        int even_count = n - odd_count;
        int larpity_wins = 0;

        if (odd_count == 1 && even_count == 1)
        {
            larpity_wins = 1;
        }
        else if (odd_count == 3 && even_count == 0)
        {
            larpity_wins = 1;
        }

        if (larpity_wins == 1)
        {
            cout << "Larpity" << '\n';
        }
        else
        {
            cout << "Moggity" << '\n';
        }
    }

    return 0;
}