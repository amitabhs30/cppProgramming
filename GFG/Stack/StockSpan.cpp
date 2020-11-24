#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void printSpan(vector<int>arr)
{
    stack<int> s;
    s.push(0);
    cout<<"1 ";
    for(int i=1;i<arr.size();i++)
    {
        while(s.empty()==false&&arr[i]>arr[s.top()])
        {
            s.pop();
        }
        int span=(s.size()>0)?i-s.top():i+1;
        cout<<span<<" ";
        s.push(i);
    }
}





// vector<int> stockSpan(vector<int> arr)//My try....
// {
//     stack<int> s;
//     vector<int> res(arr.size());
//     res[0] = 1;
//     s.push(0);
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (arr[i] < arr[s.top()])
//         {
//             res[i] = i - s.top();
//             s.push(i);
//         }
//         else
//         {
//             s.pop();
//             while (!(s.empty()) && arr[i] > arr[s.top()])
//             {
//                 s.pop();
//             }
//             if (s.empty())
//                 res[i] = i + 1;
//             else
//                 res[i] = i - s.top();
//             s.push(i);
//         }
//     }
//     return res;
// }

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
    //vector<int> result = stockSpan(arr);
    printSpan(arr);
    // for (auto x : result)
    // {
    //     cout << x << " ";
    // }
    cout << "\n";
    return 0;
}