#include <iostream>
#include <vector>
#include <map>

#define ll long long
using namespace std;

int main()
{
    int n, m;
    ll maxe = INT32_MIN;
    cin >> n;
    vector<ll> ranks(n);
    map<ll, int> rankMap;
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> ranks[i];
        if (rankMap.find(ranks[i]) == rankMap.end())
        {
            rankMap[ranks[i]] = rank;
            rank++;
            maxe = max(maxe, ranks[i]);
        }
    }
    cin >> m;
    vector<ll> playerS(m);
    vector<int> result(m);
    for (int i = 0; i < m; i++)
    {
        cin >> playerS[i];
        if (rankMap.find(playerS[i]) != rankMap.end())
        {
            result[i] = rankMap[playerS[i]];
        }
        else
        {
            if (playerS[i] > maxe)
                result[i] = 1;
            else
            {
                auto it = rankMap.lower_bound(playerS[i]);
                auto j = (*it).second;
                result[i] = (*it).second + 1;
            }
        }
    }
    for (auto x : result)
    {
        cout << x << endl;
    }
    return 0;
}