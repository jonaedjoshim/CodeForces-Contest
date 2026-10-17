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

        vector<long long> arr(n);

        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            arr[i - 1] = x + n - i;
        }

        sort(arr.begin(), arr.end());

        int ans = 1;
        int current = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1] + 1)
            {
                current++;
            }
            else if (arr[i] == arr[i - 1])
            {
            }
            else
            {
                current = 1;
            }

            if (current > ans)
            {
                ans = current;
            }
        }

        cout << ans << endl;
    }

    return 0;
}