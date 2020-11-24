#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findLongestLength(string s)
{
    int pos[256]={-1};
    int res=INT32_MIN;
    int count=0;
    for(int i=0;i<s.length();i++)
    {   
        if(pos[s[i]]==-1)
        {
            count++;
            res=max(res,count);
            pos[s[i]]=i;
        }
        else
        {
            count=i-(pos[s[i]]+1);
        }
    }
    cout<<"Longest length of distinct characters: "<<res;
}

int main()
{
    string s1;
    cout << "Enter the String of characters";
    getline(cin, s1);

    return 0;
}
