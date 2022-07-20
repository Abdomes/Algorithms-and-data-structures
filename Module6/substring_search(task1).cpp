#include<iostream>
#include<vector>

using namespace std;

class kmp
{
private:
    string pattern;
    string text;
    vector<int>pi;
public:
    kmp(string pattern, string text)
    {
        this->pattern = pattern;
        this->text = text;
        pi.resize(pattern.size());
    }

    void prefix_function()
    {
        for (int i = 1; i < pattern.size(); ++i)
        {
            int j = pi[i - 1];
            while (pattern[i] != pattern[j] && j > 0)
            {
                j = pi[j - 1];
            }
            if (pattern[i] == pattern[j])
            {
                ++j;
            }
            pi[i] = j;
        }
    }

    void start_found_pattern(int index)
    {
        cout << index << " ";
    }

    void substring_search()
    {
        prefix_function();
        for (int i = 0, j = 0; i < text.size(); ++i)
        {
            while (text[i] != pattern[j] && j > 0)
            {
                j = pi[j - 1];
            }
            if (text[i] == pattern[j])
            {
                ++j;
                if (pattern.size() == j)
                {
                    start_found_pattern(i - j + 1);
                }
            }
        }
    }
};

int main()
{
    string pattern;
    string text;
    cin >> pattern >> text;
    kmp kmp1(pattern, text);
    kmp1.substring_search();
}
