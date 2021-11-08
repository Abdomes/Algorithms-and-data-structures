#include<iostream>

#include<string>

#include<assert.h>

using namespace std;

class stack
{
public:
    stack()
    {
        size = 0;
        buffer_size = 1;
	buffer = new char[buffer_size];
    }
    ~stack()
    {
	delete[]buffer;
    }
    int getsize() { return size; }
    void grow()
    {
        int newbuffersize = buffer_size * 2;
	char* newbufer = new char[newbuffersize];
	for (int i = 0; i < buffer_size; i++)
	{
	    newbufer[i] = buffer[i];
	}
	delete[] buffer;
	buffer = newbufer;
	buffer_size = buffer_size * 2;
    }
    void push_back(char data)
    {
	if (size == buffer_size)
	{
	    grow();
	}
	assert(size < buffer_size&& buffer_size != 0);
	buffer[size] = data;
	size++;
    }
    char pop_back()
    {
        if (size == 0)
	{
	    return '0';
	}
	else if (size != 0)
	{
	    return buffer[--size];
	}
    }
    char top_back()
    {
        if (size ==     0)
	{
	    return '0';
	}
	else
	{
	    return buffer[size - 1];
	}
    }
private:
    char* buffer;
    int buffer_size;
    int size;
};

void anagram(string& word1, string& word2)
{
    stack a;
    int j = 0;
    for (int i = 0; i < word2.size(); i++)
    {
        for (j; j < word1.size(); )
	{
	    if (a.top_back() == word2[i])
	    {
                ++j;
		a.pop_back();
		break;
	    }
	    else if (word2[i] == word1[j])
	    {
	        a.push_back(word1[j]);
		++j;
		a.pop_back();
		break;
	    }
	    else
	    {
                a.push_back(word1[j]);
		++j;
	    }
        }
	if (j == word1.size() && a.top_back() == word2[i])
	{
            a.pop_back();
        }
    }
    if (a.getsize() == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    assert(word1.size() <= 10000 && word2.size() <= 10000);
    anagram(word1, word2);
}
