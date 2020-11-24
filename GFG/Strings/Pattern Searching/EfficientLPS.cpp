#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int>fillLps(string s)
{
    vector<int>LPS(s.length());
    int i=1,len=0;
    LPS[0]=0;
    while(i<s.length())
    {
        if(s[i]==s[len])
        {
            LPS[i]=len+1;
            len++;
            i++;
        }
        else
        {
            if(len==0)
            {
                LPS[i]=0;
                i++;
            }
            else
            {
                len=LPS[len-1];
            }
        }
        
    }
    return LPS;
}

int main()
{
    string s1;
    cout << "Enter the String of characters";
    getline(cin, s1);

    vector<int>result=fillLps(s1);
    cout<<endl;
    for(auto e: result)
    {
        cout<<e<<" ";
    }
    
    return 0;
}

