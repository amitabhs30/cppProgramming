#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    string s1;
    getline(cin, s1);
    unordered_map<string,int>us;
    for(long long int i=0;i+10<=s1.length();i++)
    {
        string cut=s1.substr(i,10);
        if(us.find(cut)!=us.end())
        {
            if(us[cut]==-1)
            {
                continue;
            }
            else
            {
                cout<<cut<<endl;    
                us[cut]=-1;
            }
        }
        else
        {
            us[cut]=0;
        }
    } 
    return 0;
}
