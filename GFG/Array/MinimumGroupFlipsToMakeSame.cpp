#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void FindMinFlips(vector<bool>, int);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<bool> arr;
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    FindMinFlips(arr, size);
    return 0;
}
void FindMinFlips(vector<bool> arr, int end)
{
    int flag = 0;
    for (int i = 1; i < end; i++)
    {
        if ((arr[i - 1] != arr[i]) && (flag == 0))
        {
            flag = 1;
            cout << "FROM" << i << "TO";
        }
        else if ((arr[i - 1] != arr[i]) && (flag == 1))
        {
            flag = 0;
            cout << i - 1 << endl;
        }
        else if(flag==1&&i==end-1)
        {
            cout<<i<<endl;
        }
    }
}
//In this algorithm we always flip whatever is the different 0 or 1... for eg in 1 1 0 0 0 1 1 we will flip all the zero
//also for eg 1 1 1 0 0 1 1 0 0 1 in this we will flip both the groups of zero. 