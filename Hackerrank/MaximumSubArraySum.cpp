#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        long long int x;
        long int m;
        cin >> n >> m;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            a.push_back(x);
        }

        int maxSum=a[0];

        for(int i=1;i<a.size()-1;i++)
        {
            maxSum=max(a[i]%m,(a[i-1]+a[i]%m));
        }

        t--;
    }

    return 0;
}