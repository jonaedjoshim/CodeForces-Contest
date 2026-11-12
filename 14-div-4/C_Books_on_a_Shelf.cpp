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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<int> left;
        vector<int> right;
        vector<int> mid;
        int k = 0;

        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && a[j] == a[i])
            {
                j++;
            }

            int c = j - i;
            int v = a[i];

            if (j == n)
            {
                for (int p = 0; p < c; p++)
                {
                    mid.push_back(v);
                }
                if (c >= 2)
                {
                    k += 2;
                }
                else
                {
                    k += 1;
                }
            }
            else
            {
                if (c == 1)
                {
                    left.push_back(v);
                    k += 1;
                }
                else
                {
                    for (int p = 0; p < c - 1; p++)
                    {
                        left.push_back(v);
                    }
                    right.push_back(v);
                    k += 2;
                }
            }

            i = j;
        }

        cout << k << '\n';

        for (int p = 0; p < (int)left.size(); p++)
        {
            cout << left[p] << ' ';
        }
        for (int p = 0; p < (int)mid.size(); p++)
        {
            cout << mid[p] << ' ';
        }
        for (int p = (int)right.size() - 1; p >= 0; p--)
        {
            cout << right[p];
            if (p > 0)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}