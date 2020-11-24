#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void boundaryTraversal(vector<vector<int> >);
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
    boundaryTraversal(arr);
    return 0;
}
void boundaryTraversal(vector<vector<int> > arr)
{
    if(arr[0].size()==1)
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i][0]<<" ";
        }
        return;
    }
    else if(arr.size()==1)
    {
        for(int i=0;i<arr[0].size();i++)
        {
            cout<<arr[0][i]<<" ";
        }
        return;
    }
    int i=0,j=0;
    while(j<arr[0].size())
    {
        cout<<arr[i][j]<<" ";
        j++;
    }
    j--;
    i++;
    while(i<arr.size())
    {
       cout<<arr[i][j]<<" ";
        i++;
    }
    i--;
    j--;
    while(j>=0)
    {
        cout<<arr[i][j]<<" ";
        j--;
    }
    j++;
    i--;
    while(i>0)
    {
        cout<<arr[i][j]<<" ";
        i--;
    }
}