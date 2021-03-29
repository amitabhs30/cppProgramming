#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int,long>mp;
int fibTabulation(int n,vector<long long>&arr){

    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for(int i=3;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
}

int fibRecursive(int n){
    if(n<=2)
    {
        return 1;
    }
    return fibRecursive(n-1)+fibRecursive(n-2);
}

long fibMemoization(long n){
    if(n<=2)
        return 1;
    if(mp.find(n)==mp.end())
    {
        mp.insert(make_pair(n,fibMemoization(n-1)+fibMemoization(n-2)));
        //return mp.at(n);
    }
    return mp.at(n);
}

int main(){

    long n;
    
    cin>>n;
    vector<long long>arr2(n+1,-1);
    arr2[1]=1;
    arr2[2]=1;
    mp.insert(make_pair(1,1));
    mp.insert(make_pair(2,1));
    long a=fibMemoization(n);
    //fibRecursive(n);
    long b=fibTabulation(n,arr2);

    // if(mp.at(n)==arr2[n])
    // {
    //     cout<<"Hurray!";
    // }
    // else{
    //     cout<<mp.at(n)<<" "<<arr2[n];
    // }

    // for(int i=1;i<=n;i++)
    // cout<<arr[i]<<" ";

    cout<<mp.at(n);

    return 0;
}