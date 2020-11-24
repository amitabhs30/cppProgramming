#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > arr;
void transpose();
void rotateBy90();
int main()
{
    int r, c, e;
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
    transpose();
    return 0;
}
void transpose()
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
    rotateBy90();//we basically have to reverse the matrix after transpose for 90 degree rotation.
}
void rotateBy90()
{
    int i=0,j=arr.size()-1;

    while(i<j)
    {
        for(int k=0;k<arr[0].size();k++)
        {
            int temp=arr[i][k];
            arr[i][k]=arr[j][k];
            arr[j][k]=temp;
        }
        i++;j--;
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