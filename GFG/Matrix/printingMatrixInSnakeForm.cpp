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
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = arr[0].size() - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}