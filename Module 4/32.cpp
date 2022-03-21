#include<iostream>
#include<vector>
#include<string>

using namespace std;

void number_banknotes(vector<int>&par, vector<pair<int, string>>&dp, int n, int s)
{
    for (size_t i = 1; i <= s; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (par[j] <= i && dp[i - par[j]].first != -1)
            {
                if (dp[i].first == -1)
                {
                    dp[i].first = dp[i - par[j]].first + 1;
                    dp[i].second = dp[i - par[j]].second + to_string(par[j]) + " ";
                }
                else
                {
                    int tmp = dp[i].first;
                    dp[i].first = min(dp[i].first, dp[i - par[j]].first + 1);
                    if (tmp != dp[i].first)
                    {
                        dp[i].second = "";
                        dp[i].second = dp[i - par[j]].second + to_string(par[j]) + " ";
                    }
                }
            }
        }
    }
}

int main()
{
    int n, s;
    cin >> n;
    vector<int>par(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> par[i];
    }
    cin >> s;
    vector<pair<int, string>>dp(s + 1, { -1,"" });
    dp[0].first = 0;
    number_banknotes(par, dp, n, s);
    if (dp[s].first == -1)
    {
        cout << "-1";
    }
    else
    {
        cout << dp[s].first << endl << dp[s].second;
    }
}
