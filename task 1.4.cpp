#include<iostream>

#include<assert.h>

using namespace std;

int NOD(int& n, int& A)
{
    for (int i = 2; i <= n / 2; i++)
    {
	if (n % i == 0)
	{
	    return A = n / i;
	}
    }
	return A = 1;
}

int main()
{
    int n, A, B;
    cin >> n;
    assert(1 < n && n <= 10000000);
    NOD(n, A);
    B = n - A;
    cout << A << " " << B;
}
