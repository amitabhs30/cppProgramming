#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int u;
    int v;
    int w;

    edge(int x, int y, int z)
    {
        u = x;
        v = y;
        w = z;
    }
};

vector<int> BellmanFord(vector<edge *> edges, int v, int s, bool &isncycle)
{
    vector<int> dist(v, INT16_MAX);
    dist[s] = 0;
    for (int i = 0; i < v; i++)
    {
        for (auto e : edges)
        {
            if (dist[e->v] > dist[e->u] + e->w)
                dist[e->v] = dist[e->u] + e->w;
        }
    }
    for (auto e : edges)
        if (dist[e->v] > dist[e->u] + e->w)
            isncycle = true;

    return dist;
}

int main()
{
    int v, e, s;
    cout << "Enter the no. of vertices and edges";
    cin >> v >> e;

    vector<edge *> edges(e, NULL);

    cout << "Enter the edges";

    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = new edge(x, y, z);
    }
    cout << "Enter the source";
    cin >> s;
    bool isncycle = false;
    vector<int> dist = BellmanFord(edges, v, s, isncycle);
    if (isncycle)
    {
        cout << "Negetive cycle is present!";
    }
    else
    {
        for (int i = 0; i < dist.size(); i++)
        {
            cout << s << " to " << i << " dist= " << dist[i] << endl;
        }
    }
    return 0;
}

/*

4 5

0 1 1
0 2 4
1 2 -3
1 3 2
2 3 3

0
*/