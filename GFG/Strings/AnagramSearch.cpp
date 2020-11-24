#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void findAnagram(string txt,string pat)
{
    unordered_set<char>charSet;
    for(auto e:pat)
    {
        charSet.insert(e);
    }
    int count=0;
    for(int i=0;i<txt.length();i++)
    {
        if(charSet.find(txt[i])!=charSet.end())
        {
            count++;
            if(count==pat.length())
            {
                cout<<"Present";
                return;
            }
        }
        else
        {
            count=0;
        }

    }
    cout<<"Not Present";
}

int main()
{
    string txt, pat;
    cout << "Enter the Text";
    getline(cin, txt);
    cout << "Enter the Pattern";
    getline(cin, pat);
    findAnagram(txt,pat);
    cout << endl;
    return 0;
}
