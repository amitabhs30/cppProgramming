#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool isCyclePresent = false;
bool *visited;

void addEdge(vector<int> adl[], int v1, int v2)
{
    adl[v1].push_back(v2);
    adl[v2].push_back(v1);
}

bool dfsrecur(vector<int> adl[], vector<bool> &visited, int v, int s, int parent)
{
    visited[s]=true;
    for (auto e : adl[s])
    {
        if (!visited[e])
        {
            if (dfsrecur(adl, visited, v, e, s))
                return true;
        }
        else if (e != parent)
        {
            return true;
        }
    }
    return false;
}

bool detectLoop(vector<int> adl[], int v)
{
    vector<bool> visited(v);
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfsrecur(adl, visited, v, i, -1))
                return true;
        }
    }
    return false;
}

int main()
{

    int v, e;

    cout << "Enter the No. of vertices";
    cin >> v;
    vector<int> adl[v];
    visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    cout << "Enter the No. of edges";
    cin >> e;
    int v1, v2;
    cout << "Enter the Edges";

    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;
        addEdge(adl, v1, v2);
    }
    if (detectLoop(adl, v))
        cout << "Loop is present";
    else
        cout << "No loop";
    delete visited;
    return 0;
}