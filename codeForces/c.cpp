#include <iostream>

#include <cmath>

using namespace std;

long long int a[400002], s, r;

int main()

{

	int t;

	cin >> t;

	for (int i = 0; i < t; i++)

	{

		int n;

		cin >> n;

		a[0] = 0;
		a[n + 1] = 0;

		for (int j = 1; j <= n; j++)

		{

			cin >> a[j];
		}

		s = 0;

		r = 0;

		for (int j = 1; j <= n; j++)

		{

			// r=r+abs(a[j]-a[j+1]);

			if (a[j] > a[j - 1] && a[j] > a[j + 1])

			{

				if (a[j - 1] > a[j + 1])

				{

					s = s + a[j] - a[j - 1];

					a[j] = a[j - 1];
				}

				else

				{

					s = s + a[j] - a[j + 1];

					a[j] = a[j + 1];
				}
			}
		}

		for (int j = 0; j <= n; j++)

		{

			r = r + abs(a[j] - a[j + 1]);
		}

		cout << r + s << '\n';
	}

	return 0;
}