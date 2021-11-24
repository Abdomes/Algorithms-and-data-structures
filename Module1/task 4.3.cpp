#include<iostream>

#include<assert.h>

using namespace std;

class stack
{
public:
    stack()
    {
	size = 0;
	buffer_size = 1;
	buffer = new int[buffer_size];
    }
    ~stack()
    {
        delete[]buffer;
    }
    int getsize() { return size; }
    void grow()
    {
	int newbuffersize = buffer_size * 2;
	int* newbufer = new int[newbuffersize];
	for (int i = 0; i < buffer_size; i++)
	{
	    newbufer[i] = buffer[i];
	}
	delete[] buffer;
	buffer = newbufer;
	buffer_size = buffer_size * 2;
    }
    void push_back(int data)
    {
	if (size == buffer_size)
	{
	    grow();
	}
	assert(size < buffer_size&& buffer_size != 0);
	buffer[size] = data;
	size++;
    }
    int pop_back()
    {
	if (size == 0)
	{
	    return -1;
	}
	else if (size != 0)
	{
	    return buffer[--size];
	}
    }
private:
    int* buffer;
    int buffer_size;
    int size;
};

class queue
{
public:
    stack s1;
    stack s2;
    void replace()
    {
        while (s1.getsize())
	{
	    s2.push_back(s1.pop_back());
	}
    }
    int pop_front()
    {
        if (!s2.getsize()) 
	{
	    replace();
	}
	return s2.pop_back();
    }
    void push_back(int value) 
    {
        s1.push_back(value);
    }
};

int main()
{
    queue q;
    int a, b, n;
    cin >> n;
    assert(n <= 1000000);
    for (int i = 0; i < n; i++)
    {
	cin >> a >> b;
	if (a == 2)
	{
	    if (q.pop_front() != b)
	        {
		    cout << "NO";
		    return 0;
	        }
	}
	if (a == 3)
	{
	    q.push_back(b);
	}
    }
    cout << "YES";
}
