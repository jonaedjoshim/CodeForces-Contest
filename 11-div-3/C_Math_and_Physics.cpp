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
        
        long long sum = 0;
        int flag = 0;
        int mid_flag = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            
            if (a[i] >= 2) 
            {
                flag = 1;
            }
            if (i > 0 && i < n - 1 && a[i] >= 2) 
            {
                mid_flag = 1;
            }
        }

        if (flag == 0) 
        {
            cout << -1 << '\n';
        }
        else if (mid_flag == 1) 
        {
            cout << sum - 1 << '\n';
        }
        else 
        {
            cout << sum - (n - 1) << '\n';
        }
    }

    return 0;
}