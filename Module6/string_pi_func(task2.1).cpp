#include<iostream>
#include<vector>
#include<string>

using namespace std;

void fill(string val, vector<int>& pi)
{
    for (int i = 0; i < val.size(); i += 2)
    {
        pi.push_back(atoi(val.substr(i, 1).c_str()));
    }
}

string spf(vector<int> &pi)
{
    char c = 'a';
    string str;
    str += c;
    int count = 1;
    for (int i = 1; i < pi.size(); ++i)
    {
        if (pi[i] != 0)
        {
            str += str[pi[i] - 1];
        }
        else
        {
            str += ' ';
            vector<bool>visited(count);
            int j = pi[i - 1];
            while (j > 0)
            {
                visited[str[j] - 'a'] = true;
                j = pi[j - 1];
            }
            visited[str[j] - 'a'] = true;
            for (int j = 0; j < count; ++j)
            {
                if (!visited[j])
                {
                    str[i] = char(j + 97);
                    break;
                }
            }
            if (str[i] == ' ')
            {
                str[i] = char(97 + count++);
            }
        }
    }
    return str;
}


int main()
{
    string values;
    getline(cin, values);
    vector<int>pi;
    fill(values, pi);
    cout << spf(pi) << endl;
}

