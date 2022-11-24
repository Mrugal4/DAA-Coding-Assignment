#include <bits/stdc++.h>
using namespace std;

vector<string> allLCS(string X, string Y, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
    {
        return {""};
    }

    if (X[m - 1] == Y[n - 1])
    {
        vector<string> lcs = allLCS(X, Y, m - 1, n - 1, dp);

        for (string &str : lcs)
        {
            str.push_back(X[m - 1]);
        }

        return lcs;
    }

    if (dp[m - 1][n] > dp[m][n - 1])
    {
        return allLCS(X, Y, m - 1, n, dp);
    }

    if (dp[m][n - 1] > dp[m - 1][n])
    {
        return allLCS(X, Y, m, n - 1, dp);
    }

    vector<string> top = allLCS(X, Y, m - 1, n, dp);
    vector<string> left = allLCS(X, Y, m, n - 1, dp);

    top.insert(top.end(), left.begin(), left.end());

    return top;
}

void LCSLength(string X, string Y, int m, int n, vector<vector<int>> &dp)
{

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

set<string> LCS(string X, string Y)
{
    int m = X.length(), n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    LCSLength(X, Y, m, n, dp);

    vector<string> v = allLCS(X, Y, m, n, dp);

    set<string> lcs(make_move_iterator(v.begin()), make_move_iterator(v.end()));

    return lcs;
}

int main()
{
    cout << "Enter String A : ";
    string s1;cin >> s1;
    cout << "\nEnter String B : ";
    string s2;cin >> s2;
    cout<<endl;

    set<string> lcs = LCS(s1, s2);

    string xString = *(lcs.begin());
    int x = xString.length();
    int y = 0;
    for (string str : lcs)
    {
        y++;
    }
    cout << "Answer: x+5y = " << x << "+" << 5 << "*" << y << "=" << x + (5 * y) << endl;
    return 0;
}