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
        long long x, y;
        cin >> x >> y;

        long long s = x + y;
        long long a = x;

        for (int i = 30; i >= 0; i--)
        {
            if ((x & (1LL << i)) && !(s & (1LL << i)))
            {
                a = x >> (i + 1);
                a <<= (i + 1);

                for (int j = i - 1; j >= 0; j--)
                {
                    if (s & (1LL << j))
                    {
                        a |= (1LL << j);
                    }
                }

                break;
            }
        }

        cout << s << " " << x - a << endl;
    }

    return 0;
}