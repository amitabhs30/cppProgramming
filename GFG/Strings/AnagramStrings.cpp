#include <iostream>
#include <vector>

using namespace std;

bool checkIfAnagram(string,string);

const int CHAR = 256;
int main()
{
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    if(checkIfAnagram(s1,s2))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    return 0;
}

bool checkIfAnagram(string s1,string s2)
{
    vector<int>charac(CHAR);

    if(s1.length()!=s2.length())
    {
        return false;
    }
    for(int i=0;i<s1.length();i++)
    {
        charac[s1[i]]++;
        charac[s2[i]]--;
    }
    for(int i=0;i<CHAR;i++)
    {
        if(charac[i]!=0)
        {
            return false;
        }
    }
    return true;
}
