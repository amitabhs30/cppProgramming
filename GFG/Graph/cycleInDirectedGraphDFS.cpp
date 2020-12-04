#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adl[], int v1, int v2)
{
    adl[v1].push_back(v2);
}

bool dfsRecur(vector<int> adl[], int v, vector<bool> &visited, vector<bool> &rcst, int src)
{

    //cout<<src<<" ";
    rcst[src] = true;
    visited[src] = true;
    for (auto e : adl[src])
    {
        if (!visited[e])
        {
            if (dfsRecur(adl, v, visited, rcst, e))
                return true;
        }
        else if (rcst[e])
            return true;
    }
    rcst[src] = false;
    return false;
}

bool isCyclePresent(vector<int> adl[], int v)
{
    vector<bool> visited(v);
    vector<bool> rcst(v);
    for (int i = 0; i < v; i++)
        rcst[i] = false;
    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int i = 0; i < v; i++)
        if (!visited[i])
            if (dfsRecur(adl, v, visited, rcst, i))
                return true;
    return false;
}

int main()
{

    int v, e;

    cout << "Enter the No. of vertices";
    cin >> v;
    vector<int> adl[v];
    cout << "Enter the No. of edges";
    cin >> e;
    int v1, v2;
    cout << "Enter the Edges";
    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;
        addEdge(adl, v1, v2);
    }
    if (isCyclePresent(adl, v))
        cout << "Cycle is present";
    else
        cout << "No cycle present";
    return 0;
}

// 0 1
// 2 1
// 2 3
// 3 4
// 4 5
// 5 2