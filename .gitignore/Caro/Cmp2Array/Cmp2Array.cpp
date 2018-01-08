#include<iostream>

using namespace std;

int *inputArray(int &n) {
	cout << "ENTER COUNT ARRAY: ";
	cin >> n;

	int *iA = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		cout << "\tENTER NO " << i + 1 << ": ";
		cin >> iA[i];
	}

	return iA;
}

void output(int *a, int *b, int n, int m) {
	cout << "ARRAY FIRST: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl << "ARRAY SECOND: ";
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}

	cout << endl;
}

bool Compare(int *a, int *b, int n, int m) {
	for (int i = 0; i < n + m; i++)
	{
		int x;
		if (i<n)
			x = b[i];
		else
			x = a[i-n];

		for (int j = 0; j < m+n+1; j++)
		{
			if (j==m+n)
				return false;
		
			int y;
			if (j<m)
			{
				y = a[j];
			}
			else
			{
				y = b[j - n];
			}
			if ((x==y)&&((j!=i-m)||(j-n!=i)))
			{
				j = m + n + 1;
			}
		}
	}
	return true;
}

bool main() {
	while (true)
	{
		int *a, *b, n, m;
		cout << "INPUT ARRAY FIRST" << endl;
		a = inputArray(n);

		cout << "INPUT ARRAY SECOND" << endl;
		b = inputArray(m);


		if (Compare(a, b, n, m))
		{
			cout << "\ngiong\n";
		}
		else
		{
			cout << "\nkhac\n";
		}

		output(a, b, n, m);
		getchar();
	}return true;
}