#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct node
{
    map<char, int>child;
    map<char, int>go;
    bool is_term;
    int suf_link;
    int p;
    char pch;
    vector<int>numb, ans;
    node(int p, char pch)
    {
        is_term = false;
        suf_link = -1;
        this->p = p;
        this->pch = pch;
    }
};

class trie
{
public:
    vector<node> tree;
public:
    trie()
    {
        tree.push_back(*(new node(-1, ' ')));
    }

    void add_string(const string& str, int i)
    {
        int num = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            char c = str[i];
            if (tree[num].child.count(c) == 0)
            {
                tree[num].child[c] = tree.size();
                tree.push_back(*(new node(num, str[i])));
            }
            num = tree[num].child[c];
        }
        tree[num].is_term = true;
        tree[num].numb.push_back(i);
    }

    int get_go(int v, char c)
    {
        if (tree[v].go.count(c) == 0)
        {
            if (tree[v].child.count(c) != 0)
            {
                tree[v].go[c] = tree[v].child[c];
            }
            else
            {
                tree[v].go[c] = (v == 0) ? 0 : get_go(get_suff_link(v), c);
            }
        }
        return tree[v].go[c];
    }

    int get_suff_link(int v)
    {
        if (tree[v].suf_link == -1)
        {
            if (v == 0 || tree[v].p == 0)
            {
                tree[v].suf_link = 0;
            }
            else
            {
                tree[v].suf_link = get_go(get_suff_link(tree[v].p), tree[v].pch);
            }
        }
        return tree[v].suf_link;
    }

    void answer(int v) {
        if (tree[v].ans.size() > 0)
        {
            return;
        }
        int cur_ver = v;
        while (cur_ver != 0)
        {
            if (tree[cur_ver].is_term) 
            {
                tree[v].ans.push_back(cur_ver);
            }
            cur_ver = get_suff_link(cur_ver);
        }
    }

    void ans(string& pattern, string& text)
    {
        string cur_str = "";
        vector <int> first_let, pat_size;
        bool fl = true;
        for (size_t i = 0; i < pattern.size(); ++i)
        {
            char ch = pattern[i];
            if (ch == '?') 
            {
                if (cur_str != "")
                {
                    add_string(cur_str, first_let.size() - 1);
                    pat_size.push_back(cur_str.size());
                    cur_str = "";
                }
                fl = true;
            }
            else 
            {
                cur_str += ch;
                if (fl)
                    first_let.push_back(i);
                fl = false;
            }
        }
        add_string(cur_str, first_let.size() - 1);
        pat_size.push_back(cur_str.size());
        vector <int> an(text.size());
        int cur_ver = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            char ch = text[i];
            cur_ver = get_go(cur_ver, ch);
            answer(cur_ver);
            for (int a : tree[cur_ver].ans) 
            {
                for (int pattern_number : tree[a].numb)
                {
                    if (i - pat_size[pattern_number] - first_let[pattern_number] + 1 >= 0)
                    {
                        ++an[i - pat_size[pattern_number] - first_let[pattern_number] + 1];
                    }
                }
            }
        }
        for (int i = 0; i < an.size(); i++)
        {
            if (an[i] == first_let.size() && i + pattern.size() <= text.size()) 
            {
                cout << i << " ";
            }
        }
    }

};

int main()
{
    string pattern;
    string text;
    cin >> pattern >> text;
    trie tr;
    tr.ans(pattern, text);
}
