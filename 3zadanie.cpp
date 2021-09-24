//���� ������ ��������������� ����� a, b, c � d. ������� ��� ������������ ����� a/b � c/d, � �� ��������� ����������� 
//� ���� ������������ ����� m/n. ������� ����� m � n.
#include<iostream>
#include<assert.h>
using namespace std;

void SumFract(int& a, int& b, int& c, int& d) 
{
	int m, n;
	m = (a * d + c * b);
	n = (b * d);
	for (int i = 2; i < min(m, n); i++) 
	{
		while (m % i == 0 && n % i == 0) 
		{
			m /= i;
			n /= i;
		}
	}
	cout << m <<" "<< n;
}

int main() 
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	assert(a <= 1000 && b <= 1000 && c <= 1000 && d <= 1000);
	SumFract(a, b, c, d);
}