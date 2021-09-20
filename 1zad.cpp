#include<iostream>
using namespace std;
int main() 
{
	int n,c2=0,c5=0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int c = i;
		while (c%2==0 || c%5==0) 
		{
			if (c % 2 == 0) 
			{
				c2 += 1;
				c /= 2;
			}
			if (c % 5 == 0)
			{
				c5 += 1;
				c /= 5;
			}
		}
		
	}
	cout << min(c2, c5);
}