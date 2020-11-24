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
    vector<bool> visited(256);
    fill(visited.begin(),visited.end(),false);
    pair<char,int>result;
    result.first='\0';
    result.second=-1;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(visited[s[i]])
        {
            result.first=s[i];
            result.second=i;
        }
        else
        {
            visited[s[i]]=true;
        }
    }
    return result;
}



// pair<char, int> countCharac(string s) //completely working by using hash maps.
// {
//     unordered_map<char, int> map;
//     pair<char,int>result;
//     int minI=INT32_MAX;
//     for(int i=0;i<s.length();i++)
//     {
//         if(map.find(s[i])!=map.end())
//         {
//             if(minI>map[s[i]])
//             {
//                 minI=map[s[i]];
//                 result.first=s[i];
//                 result.second=map[s[i]];
//             }
//         }
//         else
//         {
//             map[s[i]]=i;
//         }
//     }
//     return result;
// }