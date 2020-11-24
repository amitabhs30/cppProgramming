#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void printTranspose(vector<vector<int> >);
int main()
{
    int r, c, e;
    vector<vector<int> > arr;
    cout << "Enter the no. of rows and column";
    cin >> r >> c;
    cout << "Enter the elements"<<endl;
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
    printTranspose(arr);
    return 0;
}
void printTranspose(vector<vector<int> > arr)
{   
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr[0].size();j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    cout<<endl;
    for(vector<int>v :arr)
    {
        for(int x : v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}