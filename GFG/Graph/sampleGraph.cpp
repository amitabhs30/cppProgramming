#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adl[], int v1, int v2)
{
    adl[v1].push_back(v2);
    adl[v2].push_back(v1);
}

int main()
{

    int v, e;

    cout << "Enter the No. of vertices";
    cin >> v;
    vector<int> adl[v + 1];
    cout << "Enter the No. of edges";
    cin >> e;
    int v1, v2;
    cout << "Enter the Edges";
    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;
        addEdge(adl, v1, v2);
    }
    return 0;
}