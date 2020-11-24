#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        long int size;
        int count;
        vector<long int> height;
        cin >> size;
        for (long int i = 0; i < size; i++)
        {
            cin >> count;
            height.push_back(count);
        }
        count = 0;
        sort(height.begin(), height.end());
        if(height[size-1]==0)
        {
            cout<<0<<endl;
            n--;
            continue;
        }
        long int i = size - 1;
        while (i > 0)
        {
            if (height[i] > height[i - 1])
            {
                if (height[i - 1] != 0)
                    count++;
            }
            i--;
        }

        cout << count + 1 << endl;

        n--;
    }

    return 0;
}