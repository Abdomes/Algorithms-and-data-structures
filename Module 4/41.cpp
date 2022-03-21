#include<iostream>
#include<vector>

using namespace std;

void wide_pyramid(vector<vector<unsigned long int>>& dp, int n)
{
    for (size_t i = 0; i <= n; ++i)
    {
        dp[0][i] = 1;
    }
    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= i; ++j)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1];
        }
        for (size_t k = i + 1; k <= n; ++k)
        {
            dp[i][k] = dp[i][i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<unsigned long int>>dp(n + 1, vector<unsigned long int>(n + 1));
    wide_pyramid(dp, n);
    cout << dp[n][n];
}
