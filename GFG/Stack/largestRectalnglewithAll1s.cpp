#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findLargestAreaBest(vector<int> heights)
{
    int res = INT32_MIN;
    stack<int> s;
    int curr;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!(s.empty()) && heights[s.top()] >= heights[i])
        {
            int tp = s.top();
            s.pop();
            curr = heights[tp] * ((s.empty()) ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while (!(s.empty()))
    {
        int tp = s.top();
        s.pop();
        curr = heights[tp] * ((s.empty()) ? heights.size() : heights.size() - s.top() - 1);
        res = max(res, curr);
    }
    return res;
}

int findLargestRectangleWithAllOne(vector<vector<int> > matrix)
{
    int res = 0, curr;
    vector<int> row(matrix[0].begin(), matrix[0].end());
    res=findLargestAreaBest(row);
    for(int i=1;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j])
            {
                row[j]+=matrix[i][j];
            }
            else
            {
                row[j]=0;
            }            
        }
        curr=findLargestAreaBest(row);
        res=max(res,curr);
    }
    return res;
}
int main()
{
    int r, c, e;
    vector<vector<int> > matrix;
    cout << "Enter the size of row";
    cin >> r;
    cout << "Enter the size of column";
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        vector<int> row;
        for (int j = 0; j < r; j++)
        {
            cin >> e;
            row.push_back(e);
        }
        matrix.push_back(row);
    }
    int res = findLargestRectangleWithAllOne(matrix);
    cout << res;
    return 0;
}

/*
0 1 1 0
1 1 1 1 
1 1 1 1 
1 1 0 0 



0 1 1 1 0 1 
0 1 0 1 0 1 
1 1 1 1 1 1
0 1 1 1 1 1 
*/