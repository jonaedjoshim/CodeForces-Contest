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
        int k;
        cin >> k;

        int center_tree = -1;
        int center_node = -1;

        for (int i = 1; i <= k; i++)
        {
            int n;
            cin >> n;

            vector<int> degree(n + 1, 0);
            vector<int> neighbor_xor(n + 1, 0);

            for (int j = 0; j < n - 1; j++)
            {
                int u, v;
                cin >> u >> v;
                degree[u]++;
                degree[v]++;
                neighbor_xor[u] ^= v;
                neighbor_xor[v] ^= u;
            }

            if (n >= 2 && center_tree == -1)
            {
                for (int v = 1; v <= n; v++)
                {
                    if (degree[v] == 1)
                    {
                        center_tree = i;
                        center_node = neighbor_xor[v];
                        break;
                    }
                }
            }
        }

        if (center_tree == -1)
        {
            center_tree = 1;
            center_node = 1;
        }

        for (int i = 1; i <= k; i++)
        {
            if (i != center_tree)
            {
                cout << i << ' ' << 1 << ' ' << center_tree << ' ' << center_node << '\n';
            }
        }
    }

    return 0;
}