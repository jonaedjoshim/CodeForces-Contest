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
        long long n;
        cin >> n;
        long long a = n / 2;
        long long b = n - a;
        cout << a * b << "\n";
    }

    return 0;
}