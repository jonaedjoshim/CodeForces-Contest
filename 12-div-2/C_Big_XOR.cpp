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

        int bv[20];
        int bm[20];
        int ins[20];
        int cnt = 0;

        for (int i = 0; i < 20; i++)
        {
            bv[i] = 0;
            bm[i] = 0;
            ins[i] = 0;
        }

        int base = 0;
        for (int x = 1; x <= n; x++)
        {
            base ^= x;
            int v = x ^ (2 * x);
            int mk = 0;

            for (int b = 19; b >= 0; b--)
            {
                if (((v >> b) & 1) == 0)
                {
                    continue;
                }

                if (bv[b] != 0)
                {
                    v ^= bv[b];
                    mk ^= bm[b];
                }
                else
                {
                    bv[b] = v;
                    ins[cnt] = x;
                    bm[b] = mk ^ (1 << cnt);
                    cnt++;
                    break;
                }
            }
        }

        int h = 0;
        while ((1 << (h + 1)) <= n)
        {
            h++;
        }

        vector<int> d(n + 1, 0);
        int done = 0;

        for (int w = 0; w < 2 && done == 0; w++)
        {
            int target = (1 << (h + 2)) - 2 + w;
            int need = target ^ base;
            int mk = 0;
            int flag = 1;

            for (int b = 19; b >= 0; b--)
            {
                if (((need >> b) & 1) == 0)
                {
                    continue;
                }

                if (bv[b] == 0)
                {
                    flag = 0;
                    break;
                }

                need ^= bv[b];
                mk ^= bm[b];
            }

            if (flag == 1)
            {
                done = 1;
                for (int i = 0; i < cnt; i++)
                {
                    if ((mk >> i) & 1)
                    {
                        d[ins[i]] = 1;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << d[i];
            if (i < n)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}