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

        long long arr[200005];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long small = arr[0];
        long long big = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < small)
            {
                small = arr[i];
            }
            if (arr[i] > big)
            {
                big = arr[i];
            }
        }

        long long result = small;

        if (small != big)
        {
            long long gap = small ^ big;
            int bits = 0;
            long long probe = gap;
            while (probe > 0)
            {
                bits++;
                probe >>= 1;
            }
            long long fill = (1LL << bits) - 1;
            result = big | fill;
        }

        cout << result << '\n';
    }

    return 0;
}