#include<iostream>
#include<vector>
using namespace std;

class suffix_array
{
private:
    string str;
    int n, alpha = 27, cl, j;
    vector<int>p, cnt;
    vector <vector<int>>c;

public:
    suffix_array(const string& str)
    {
        this->str = str;
        n = str.size();
        p.resize(n);
        j = 0;
        cnt.resize(alpha);
        c.resize(1, vector<int>(n));
    }

    int pow(int i)
    {
        return 1 << i;
    }

    void first_phase()
    {
        for (int i = 0; i < n; ++i)
        {
            ++cnt[str[i] - 'a' + 1];
        }
        for (int i = 1; i < alpha; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i)
        {
            p[--cnt[str[i] - 'a' + 1]] = i;
        }
        c[0][p[0]] = 0;
        cl = 1;
        for (int i = 1; i < n; ++i)
        {
            if (str[p[i]] != str[p[i - 1]])
                ++cl;
            c[0][p[i]] = cl - 1;
        }
    }

    void build()
    {
        first_phase();
        vector<int>tmp_p(n);
        for (j; pow(j) < n; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                tmp_p[i] = p[i] - pow(j);
                if (tmp_p[i] < 0)
                    tmp_p[i] += n;
            }
            cnt.assign(cl, 0);
            for (int i = 0; i < n; ++i)
            {
                ++cnt[c[j][tmp_p[i]]];
            }
            for (int i = 1; i < cl; ++i)
            {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; --i)
            {
                p[--cnt[c[j][tmp_p[i]]]] = tmp_p[i];
            }
            c.emplace_back(n);
            c[j + 1][p[0]] = 0;
            cl = 1;
            for (int i = 1; i < n; ++i)
            {
                int m1 = (p[i] + pow(j)) % n, m2 = (p[i - 1] + pow(j)) % n;
                if (c[j][p[i]] != c[j][p[i - 1]] || c[j][m1] != c[j][m2])
                    ++cl;
                c[j + 1][p[i]] = cl - 1;
            }
        }
    }

    int lcp()
    {
        int f = 0, s = 0, ans = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            f = p[i];
            s = p[i + 1];
            for (int k = j - 1; k >= 0; --k)
            {
                if (c[k][f] == c[k][s])
                {
                    ans += pow(k);
                    f += pow(k);
                    s += pow(k);
                }
            }
        }
        return ans;
    }

    int answer()
    {
        build();
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            ans += n - p[i] - 1;
        }
        ans -= lcp();
        return ans;
    }
};

int main()
{
    string str;
    cin >> str;
    suffix_array sa(str + "`");
    cout << sa.answer();
}
