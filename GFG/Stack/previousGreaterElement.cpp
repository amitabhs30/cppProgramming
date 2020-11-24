#include <iostream>
#include <stack>
#include <vector>


using namespace std;

void printPreviousGreaterElement(vector<int>arr)
{
    stack<int>s;
    s.push(arr[0]);
    cout<<"-1 ";
    for(int i=1;i<arr.size();i++)
    {
        while(!(s.empty())&&arr[i]>=s.top())
        {
            s.pop();
        }
        int val=s.empty()?-1:s.top();
        cout<<val<<" ";
        s.push(arr[i]);
    }
}

int main()
{
    int n, e;
    cout << "Enter the size of the array";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        arr.push_back(e);
    }
    printPreviousGreaterElement(arr);
    cout << "\n";
    return 0;
}