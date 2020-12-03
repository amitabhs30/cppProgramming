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



void dfsRecur(vector<int>adl[],int v,vector<bool>&visited,int src)
{
    cout<<src<<" ";
    visited[src]=true;
    for(auto e:adl[src])
    {
        if(!visited[e])
        {
            dfsRecur(adl,v,visited,e);
        }
    }
}


void DFS(vector<int>adl[],int v)
{
    vector<bool>visited(v);
    for(int i=0;i<v;i++)visited[i]=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfsRecur(adl,v,visited,i);
        }
    }

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
    DFS(adl,v);
    return 0;
}