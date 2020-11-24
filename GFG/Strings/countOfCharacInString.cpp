#include <iostream>
#include <vector>

using namespace std;

void countCharac(string);

int main()
{
    string s1;
    cout << "Enter the String of lower case characters";
    getline(cin,s1);
    countCharac(s1);
    return 0;
}

void countCharac(string s)
{
    vector<int>charac(26);

    for(char c:s)
    {
        charac[c-'a']++;
    }

    for(int i=0;i<26;i++)
    {
        if(charac[i]>0)
        {
            cout<<(char)('a'+i)<<" appeared "<<charac[i]<<" times"<<endl;
        }
    }
}