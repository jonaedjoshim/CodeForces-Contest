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
        int a, b, c;
        cin >> a >> b >> c;

        int total = a + b + c;
        int flag = 0;

        if (total % 3 == 0)
        {
            int mid = total / 3;
            if (a == mid - 1 && b == mid && c == mid + 1)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}