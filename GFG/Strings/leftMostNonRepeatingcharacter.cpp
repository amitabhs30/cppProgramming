#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int findLonfPropPreSuff(string s,int n)
{
    for(int len=n-1;len>0;len--)
    {
    bool flag=false;
        for(int i=0;i<len;i++)
        {
            if(s[i]==s[n-len+i])
            {
                flag=true;
            }
        }
        if(flag)
        {
            return len;
        }
    }
    return 0;
}



vector<int>giveString(string s1)
{
    vector<int>lps;
    for(int i=0;i<s1.length();i++)
    {
        lps.push_back(findLonfPropPreSuff(s1,i+1));
    }
    return lps;
}



int main()
{
    string s1;
    cout << "Enter the String of characters";
    getline(cin, s1);

    vector<int>res=giveString(s1);
    for(auto e: res)
    {
        cout<<e<<" ";
    }
    return 0;
}
