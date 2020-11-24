#include <iostream>
#include <vector>

using namespace std;

void checkForPattern(string s, string pattern)
{
    for(int i=0;i<=s.length()-pattern.length();)
    {   int j;
        for(j=0;j<pattern.length();j++)
        {
            if(pattern[j]!=s[i+j])
            {
                break;
            }
        }
        if(j==pattern.length())
        {
            cout<<i<<" ";
        }
        if(j==0)
        {
            i++;
        }
        else
        {
            i=i+j;
        }
        
    }
}

int main()
{
    string s1, s2;
    cout << "Enter the string";
    getline(cin, s1);
    cout << "Enter the pattern";
    getline(cin, s2);
    checkForPattern(s1, s2);
    return 0;
}
