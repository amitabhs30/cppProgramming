#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<char, int> countCharac(string);

int main()
{
    string s1;
    cout << "Enter the String of characters";
    getline(cin, s1);
    pair<char, int> res = countCharac(s1);
    cout << res.first << " " << res.second;
    return 0;
}

pair<char, int> countCharac(string s)
{
    vector<int> visited(256);
    fill(visited.begin(),visited.end(),-1);
    pair<char,int>result;
    result.first='\0';
    result.second=-1;

    for(int i=0;i<s.length();i++)
    {
        if(visited[s[i]]==-1)
        {
            visited[s[i]]=i;
        }
        else
        {
            visited[s[i]]=-2;
        }
    }
    result.second=INT32_MAX;
    for(auto e: s)
    {
        if(visited[e]!=-1&&visited[e]!=-2)
        {
            if(result.second>visited[e])
            {
                result.first=e;
                result.second=visited[e];
            }
        }
    }

    return result;
}


