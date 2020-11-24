#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val = 6;
        for (int j = 0, p = i + 1; j <= n - i-1; j++)
        {
            cout << p << " ";
            p += val;
            if (i % 2 != 0)
            {
                val++;
            }
            else
            {
                val--;
            }
        }
        cout<<endl;
    }
}