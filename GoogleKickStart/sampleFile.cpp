#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// int INT_MIN = -2147483648;
int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; ++z)
    {
        long int size;
        int count;
        vector<long int> arr;
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cin >> count;
            arr.push_back(count);
        }
        int maxLen=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            int j=i;
            int cd=arr[i+1]-arr[i];
            while(j<arr.size()-1&&arr[j+1]-arr[j]==cd)
            j++;
            int max_j=j;
            maxLen=max(maxLen,max_j-i+1);
            i=max(i+1,j);
        }
        cout << "Case #" << z << ": "<<maxLen<<endl;
        }
    return 0;
}
