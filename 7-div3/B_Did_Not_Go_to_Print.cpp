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

        string commands;
        cin >> commands;

        vector<int> memory;
        vector<int> printed(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (commands[i - 1] == '1')
            {
                memory.push_back(i);
            }
            else if (commands[i - 1] == '2')
            {
                if (memory.empty())
                {
                    printed[i] = 1;
                }
                else
                {
                    int doc = memory.back();
                    memory.pop_back();
                    printed[doc] = 1;
                }
            }
            else
            {
                printed[i] = 1;
            }
        }

        vector<int> notPrinted;

        for (int i = 1; i <= n; i++)
        {
            if (printed[i] == 0)
            {
                notPrinted.push_back(i);
            }
        }

        cout << notPrinted.size() << '\n';

        for (int i = 0; i < notPrinted.size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << notPrinted[i];
        }

        cout << '\n';
    }

    return 0;
}