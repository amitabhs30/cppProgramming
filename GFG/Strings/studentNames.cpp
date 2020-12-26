#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Student
{

public:
    string name;
    vector<string> elderThan;
    vector<string> youngerThan;
    Student(string nam)
    {
        name = nam;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        unordered_map<string, pair<int, int> > map;
        for (int i = 0; i < n; i++)
        {

            string nam;
            cin >> nam;
            map[nam].second = 0;
            map[nam].first = i;
        }
        string s2, eld, yon;
        int m;
        cin>>m;
        for (int i = 0; i <= m; i++)
        {
            getline(cin,s2);
            istringstream ss(s2);
            string name;
            while(ss>>name)
            {
                map[name].second++;
                break;
            }
        }
        int res = 0;
        for (auto x : map)
        {
            int chk = n - x.second.first - 1;
            if (x.second.second == chk)
                res++;
        }
        return 0;
    }
}