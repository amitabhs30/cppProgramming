#include "/Users/amitabh/stdc++.h"
//#include<vector>
using namespace std;

void sample(int, vector<int>&, vector<int>&);


int main() {
	int T, N;
	cin >> T;
	for(int i=0; i<T; i++){
	    cin>>N;
	    vector<int>arr(N);
	    vector<int>arr1(N);
	    for(int j=0; j<N; j++){
	        cin>>arr[j];
	    }
	    arr1.assign(arr.begin(), arr.end());
	    sort(arr1.begin(), arr1.end());
	    
	    sample(N, arr, arr1);
	    
	}
	
	return 0;
}
void sample(int x, vector<int>& arr, vector<int>& arr1){
    vector<int> time(arr1.size());
    int count=1;
    for(int i=x-1; i>=0; i--){
        for(int j=0; j<x; j++){
            if(arr[j]==arr1[i]){
                time[j]=count;
                arr[j]=-1;
              
            }
        }
        count++;
        
    }
    for(int i=0; i<x; i++){
        cout<<time[i]<<"";
    }
    
    
}