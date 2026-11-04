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

        vector<vector<int>> a(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        if (n % 2 == 0)
        {
            cout << n + 1 << '\n';
            continue;
        }

        int lev = 1;
        while ((1 << lev) <= n)
        {
            lev++;
        }

        vector<vector<int>> up(lev, vector<int>(n + 1, 1));
        vector<int> par(n + 1, 0);
        vector<int> dep(n + 1, 0);
        vector<int> bfs;
        bfs.push_back(1);

        for (int i = 0; i < (int)bfs.size(); i++)
        {
            int v = bfs[i];
            for (int w : a[v])
            {
                if (w == par[v])
                {
                    continue;
                }
                par[w] = v;
                dep[w] = dep[v] + 1;
                up[0][w] = v;
                bfs.push_back(w);
            }
        }

        for (int j = 1; j < lev; j++)
        {
            for (int v = 1; v <= n; v++)
            {
                up[j][v] = up[j - 1][up[j - 1][v]];
            }
        }

        int mx = -1;
        int best_k = n;

        for (int k = n; k <= n + 2; k++)
        {
            vector<int> df(n + 1, 0);
            int start = max(1, k - n);
            int end = min(n, k - 1);

            for (int i = start; i <= end; i++)
            {
                int j = k - i;
                if (i >= j)
                {
                    continue;
                }

                int u = i;
                int v = j;
                if (dep[u] < dep[v])
                {
                    swap(u, v);
                }

                int diff = dep[u] - dep[v];
                for (int b = 0; b < lev; b++)
                {
                    if ((diff >> b) & 1)
                    {
                        u = up[b][u];
                    }
                }

                int l;
                if (u == v)
                {
                    l = u;
                }
                else
                {
                    for (int b = lev - 1; b >= 0; b--)
                    {
                        if (up[b][u] != up[b][v])
                        {
                            u = up[b][u];
                            v = up[b][v];
                        }
                    }
                    l = up[0][u];
                }

                df[i]++;
                df[j]++;
                df[l]--;
                if (par[l] != 0)
                {
                    df[par[l]]--;
                }
            }

            int cov = 0;
            for (int h = n - 1; h >= 0; h--)
            {
                int v = bfs[h];
                if (df[v] > 0)
                {
                    cov++;
                }
                if (par[v] != 0)
                {
                    df[par[v]] += df[v];
                }
            }

            if (cov > mx)
            {
                mx = cov;
                best_k = k;
            }
        }

        cout << best_k << '\n';
    }

    return 0;
}