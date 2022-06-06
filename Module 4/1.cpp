#include<iostream>
#include<vector>
#include<string>

using namespace std;

int h(string str, int buffer_size)
{
    int hash = 0;
    int a = 997;
    for (int i = 0; i < str.size(); i++)
    {
        hash = (hash * a + str[i]) % buffer_size;
    }
    return hash;
}

class hash_table
{
public:
    hash_table()
    {
        buffer_size = 8;
        size = 0;
        table.resize(buffer_size);
    }

    double load_factor()
    {
        return size / buffer_size;
    }

    void recalc()
    {
        buffer_size *= 2;
        vector<string>elements;
        for (int i = 0; i < table.size(); ++i) {
            if (table[i] != "" && table[i] != "D") {
                elements.push_back(table[i]);
            }
        }
        table.clear();
        size = 0;
        table.resize(buffer_size);
        for (int i = 0; i < elements.size(); ++i)
        {
            add(elements[i]);
        }
    }

    bool add(string str)
    {
        int i = 0;
        int hash = h(str, buffer_size);
        while (table[hash] != "" && table[hash] != "D")
        {
            if (table[hash] == str)
            {
                return false;
            }
            hash = (hash + ++i) % buffer_size;
        }
        table[hash] = str;
        ++size;
        if (load_factor() > 0.75)
        {
            recalc();
        }
        return true;
    }

    bool remove(string str)
    {
        int hash = h(str, buffer_size);
        int i = 0;
        while (table[hash] != "" && i < buffer_size)
        {
            if (table[hash] == str)
            {
                table[hash] = "D";
                --size;
                return true;
            }
            hash = (hash + ++i) % buffer_size;
        }
        return false;
    }

    bool find(string str)
    {
        int hash = h(str, buffer_size);
        int i = 0;
        while (table[hash] != "" && i < buffer_size)
        {
            if (table[hash] == str)
            {
                return true;
            }
            hash = (hash + ++i) % buffer_size;
        }
        return false;
    }

private:
    double size;
    int buffer_size;
    vector<string>table;
};

int main()
{
    hash_table table;
    string str;
    char s;
    while (cin >> s >> str)
    {
        if (s == '+') {
            table.add(str) ? cout << "OK" << endl : cout << "FAIL" << endl;
        }
        else if (s == '-') {
            table.remove(str) ? cout << "OK" << endl : cout << "FAIL" << endl;
        }
        else if (s == '?') {
            table.find(str) ? cout << "OK" << endl : cout << "FAIL" << endl;
        }
    }
    return 0;
}
