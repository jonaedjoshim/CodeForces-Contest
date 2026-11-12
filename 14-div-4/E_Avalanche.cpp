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

        vector<int> piles(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> piles[i];
        }

        vector<int> moves(n + 2, 0);
        int activeWindow = 0;
        int totalMoves = 0;

        for (int i = n; i >= 1; i--)
        {
            moves[i] = (piles[i] % 2 + activeWindow) % 2;
            totalMoves += moves[i];
            activeWindow += moves[i];

            if (i + k <= n)
            {
                activeWindow -= moves[i + k];
            }
        }

        if (totalMoves % 2 == 1)
        {
            cout << "Alice" << '\n';
        }
        else
        {
            cout << "Bob" << '\n';
        }
    }

    return 0;
}