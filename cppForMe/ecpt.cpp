#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<char>val;
    for(int i=0;i<131;i++)
    {
        int x;
        cin>>x;
        val.push_back(x);
    }
    for(int i=0;i<(131);i++)
    {   
        cout<<(char)val[i];
    }
    return 0;
}