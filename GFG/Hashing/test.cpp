#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


unordered_map<int, int> um;


int firstRepeated(int *, int);

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> arr[i] ;
            
        cout << firstRepeated(arr,n) << "\n";
    }

    return 0;
}
// } Driver Code Ends


int firstRepeated(int arr[], int n) {
    unordered_map<int,bool>map;
    
    for(int i=0;i<n;i++)
    {
        if(map.find(arr[i])!=map.end())
        {
            map[arr[i]]=1;
        }
        else
        map[arr[i]]=0;
    }  
    for(int i=0;i<n;i++)
    {
        if(map[arr[i]])
        {
            return i+1;
        }
    }
    return -1;
}
