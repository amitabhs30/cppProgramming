#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void findProductKey(vector<vector<int> >, int ,int );
int main()
{
    int r, c, e;
    vector<vector<int> > arr;
    cin >> r >> c;
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
    findProductKey(arr,r ,c);
    return 0;
}
void findProductKey(vector<vector<int> > arr, int r, int c)
{
    vector<int>res;
    vector<int>a(arr[0].begin(),arr[0].end());
    sort(a.begin(),a.end());
    for(int i=0;i<c;i++)
    {
        int find=a[i];
        int count=0;

    for(int j=1;j<r;j++)
    {
        vector<int>v(arr[j].begin(),arr[j].end());
        sort(v.begin(),v.end());
        if(binary_search(v.begin(),v.end(),find))
        {
            count++;
        }
    }
    if(count==r-1)
    {
        res.push_back(find);
    }
    }
    for(int x : res)
    {
        printf("%d ",x);
    }
    
}
