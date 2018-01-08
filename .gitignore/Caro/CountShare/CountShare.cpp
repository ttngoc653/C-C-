#include<iostream>

using namespace std;

int main() {
	while (true)
	{
		int m, n, c = 1;
		cout << "ENTER HEIGHT: ";
		cin >> m;

		cout << "ENTER WIDTH: ";
		cin >> n;

		while (m != n)
		{
			c++;
			if (m > n)
			{
				cout << n;
				m -= n;
			}
			else
			{
				cout << m;
				n -= m;
			}
			cout << ", ";
		}
		cout << m << endl;
		cout << "COUNT SQUARE: " << c << endl << endl;
	}
	return 0;
}