
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<pair<int,int> >findResult(vector<int>arr,int);
int main()
{
    int size, n;
    cout << "Enter the size of array";
    scanf("%d", &size);
    vector<int> arr;
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    cout<<"Enter k";
    cin>>n;
    vector<pair<int,int> > = findResult(arr,n);
    cout << endl
         << "Elements occouring more than n/k are: "<<res;
    for(auto e:arr)
    {
        cout<<e.first<<" is occouring"<<e.second<<" times"<<endl;
    }
    return 0;
}
vector<pair<int,int>> findResult(vector<int> arr, int k){
    unordered_map<int,int>map;
    vector<pair<int,int> >result;
    for(auto e: arr)
    {
        map[e]++;
    }
    for(auto e: map)
    {
        if(e.second>(arr.size()/k))
        {
            result.push_back(e);
        }
    }
    return result;
}