#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int MooresVotingAlgo(vector<int>, int);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int> arr;
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    int res = MooresVotingAlgo(arr, size);
    if(res>0)
    cout << arr[res] << " Is the majority element" << endl;
    else
    {
        cout<<"No Majority Element";
    }
    
    return 0;

}

int MooresVotingAlgo(vector<int> arr, int end) // A very famous algorithm known as Moores Voting algo,
                                               // works in O(n) time complexity.
{
    int count = 1, index = 0;
    for (int i = 1; i < end; i++)
    {
        if (arr[i] == arr[index])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            index = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < end; i++)
    {
        if (arr[i] == arr[index])
        {
            count++;
        }
    }
    if (count <= end / 2)
    {
        return -1;
    }
    else
    {
        return index;
    }
}