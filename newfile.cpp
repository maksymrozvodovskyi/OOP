#include <iostream>
using namespace std;

int main()
{
	cout << "enter number: ";

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = N; j >= i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << i;
		}
		for (int j = 0; j < i; j++)
		{
			cout << j;
		}
		cout << endl;
	}
}

