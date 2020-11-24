#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<vector<int> >);
int main()
{
    int r, c, e;
    vector<vector<int> > arr;
    cout << "Enter the no. of rows and column";
    cin >> r >> c;
    cout << "Enter the elements";
    for (int i = 0; i < r; i++)
    {
        vector<int> v;
        for (int j = 0; j < c; j++)
        {
            cin >> e;
            v.push_back(e);
        }
        arr.push_back(v);
    }
    print(arr);
    return 0;
}
void print(vector<vector<int> > arr)
{
    int top, right, left, bottom;
    left = 0;
    top = 0;
    right = arr[0].size() - 1;
    bottom = arr.size() - 1;

    while (top < bottom && left < right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i]<<" ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right]<<" ";
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            cout << arr[bottom][i]<<" ";
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            cout << arr[i][left]<<" ";
        }
        left++;
    }
}