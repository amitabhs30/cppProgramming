#include <iostream>
#include <vector>
#include <stack>
using namespace std;




int findLargestArea(vector<int> heights)//O(n2)soln
{
    int res = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int curr = heights[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (heights[j] >= heights[i])
                curr += heights[i];
            else
                break;
        }
        for (int j = i + 1; j < heights.size(); j++)
        {
            if (heights[j] >= heights[i])
            {
                curr += heights[i];
            }
            else
                break;
        }
        res=max(curr,res);
    }
    return res;
}


vector<int> findPreviousSmallestElement(vector<int>arr)
{
    stack<int>s;
    s.push(0);
    vector<int>res(arr.size());
    res[0]=-1;
    for(int i=1;i<arr.size();i++)
    {
        while(!(s.empty())&&arr[i]<arr[s.top()])
        {
            s.pop();
        }
        res[i]=s.empty()?-1:s.top();
        s.push(i);
    }
    return res;
}
vector<int> findNextSmallestElement(vector<int>arr)
{
    stack<int>s;
    vector<int>res(arr.size());
    s.push(arr.size()-1);
    res[arr.size()-1]=arr.size();
    for(int i=arr.size()-2;i>=0;i--)
    {
        while(!(s.empty())&&arr[i]<arr[s.top()])
        {
            s.pop();
        }
        res[i]=s.empty()?arr.size():s.top();
        s.push(i);
    }

    return res;
}

int findLargestBetter(vector<int>heights)
{   
    vector<int>prevSmallest=findPreviousSmallestElement(heights);
    vector<int>nextSmallest=findNextSmallestElement(heights);
    int res=0;

    for(int i=0;i<heights.size();i++)
    {
        int curr=heights[i];
        curr+=(i-prevSmallest[i]-1)*heights[i];
        curr+=(nextSmallest[i]-i-1)*heights[i];
        res=max(res,curr);
    }
    return res;
}
int findLargestAreaBest(vector<int>heights)
{
    int res=INT32_MIN;
    stack<int>s;
    int curr;
    for(int i=0;i<heights.size();i++)
    {   
        while(!(s.empty())&&heights[s.top()]>=heights[i])
        {   
            int tp=s.top();
            s.pop();
            curr=heights[tp]*((s.empty())?i:(i-s.top()-1));
            res=max(res,curr);
        }
        s.push(i);
    }
    while(!(s.empty()))
    {
       int tp=s.top();
       s.pop();
       curr=heights[tp]*((s.empty())?heights.size():heights.size()-s.top()-1);
       res=max(res,curr);
    }
    return res;
}   
int main()
{
    int n, e;
    vector<int> arr;
    cout << "Enter the no. of rectangles";
    cin >> n;
    cout << "Enter the size of each rectangle";
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        arr.push_back(e);
    }
    int res = findLargestAreaBest(arr);
    cout << res;
    return 0;
}