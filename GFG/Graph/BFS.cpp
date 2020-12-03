#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool * visited;

void addEdge(vector<int> adl[], int v1, int v2)
{
    adl[v1].push_back(v2);
    adl[v2].push_back(v1);
}


void BFS(vector<int>adl[],int v, int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(auto v : adl[cur])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

void findSource(vector<int> adl[], int v )
{
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            int src=i;
            BFS(adl,v,i);
        }
    }
}




int main()
{

    int v, e;

    cout << "Enter the No. of vertices";
    cin >> v;
    vector<int> adl[v];
    visited =new bool[v];
    for(int i=0;i<v;i++)visited[i]=false;
    cout << "Enter the No. of edges";
    cin >> e;
    int v1, v2;
    cout << "Enter the Edges";



    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;
        addEdge(adl, v1, v2);
    }

    findSource(adl,v);
    delete visited;
    return 0;
}