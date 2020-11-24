
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<pair<int,int> >findResult(vector<int>arr,int);
vector<pair<int,int> >findResult2(vector<int>arr,int);
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
    vector<pair<int,int> > res = findResult2(arr,n);
    cout << endl
         << "Elements occouring more than n/k are: "<<endl;
    for(auto e:res)
    {
        cout<<e.first<<" is occouring "<<e.second<<" times"<<endl;
    }
    return 0;
}
vector<pair<int,int> > findResult(vector<int> arr, int k){
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

vector<pair<int,int> > findResult2(vector<int> arr, int k){ //By moores Voting algorithm.
    unordered_map<int,int>map;
    vector<pair<int,int> >result;
    
    for(int i=0;i<arr.size();i++)
    {
        if(map.find(arr[i])!=map.end())
        {
            map[arr[i]]++;
        }
        else if(map.size()<k-1)
        {
            map[arr[i]]++;
        }
        else
        {
            for(auto e:map)
            {
                map[e.first]--;
                if(map[e.first]==0)
                {
                    map.erase(e.first);
                }
            }
        }
        int count=0;
        for(auto e: map)
        {
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]==e.first)
                {
                    count++;
                }
            }
            if(count>(arr.size()/k))
            {
                pair<int,int>x;
                x.first=e.first;
                x.second=count;
                result.push_back(x);
            }
        }
        return result;
    }


}

