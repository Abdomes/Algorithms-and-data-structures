#include<iostream>
#include<vector>
#include<string>

using namespace std;

class string_by_pi_func
{
private:
    vector<int>pi;
    string str;
public:
    string_by_pi_func(string val)
    {
        for (int i = 0; i < val.size(); i += 2)
        {
            pi.push_back(atoi(val.substr(i, 1).c_str()));
        }
    }

    string spf()
    {
        char c = 'a';
        for (int i = 0; i < pi.size(); ++i)
        {
            if (pi[i] == 0)
            {
                int flag = 0;
                str += "#";
                for (int k = 1; k < i; ++k)
                {
                    str[i] = str[k];
                    int j = pi[i - 1];
                    while (j > 0 && str[i] != str[j])
                    {
                        j = pi[j - 1];
                    }
                    if (str[i] == str[j])
                    {
                        ++j;
                    }
                    if (j == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    str[i] = c++;
                }
            }
            else
            {
                str += str[pi[i] - 1];
            }
        }
        return str;
    }
};

int main()
{
    string values;
    getline(cin, values);
    string_by_pi_func spf1(values);
    cout << spf1.spf();
}

