#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countTriplet(int arr[], int n)
	{
        unordered_set<int>set;
        for(int i=0;i<n;i++)
        {
            set.insert(arr[i]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=arr[i]+arr[j];
                if(set.find(x)!=set.end())
                {
                    count++;
                }
            }
        }
        return count;
	}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<countTriplet(arr,n);
	return 0;
}