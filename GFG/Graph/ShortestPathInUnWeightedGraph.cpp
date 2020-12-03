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

vector<int> findSP(vector<int>adl[],int v, int src)
{
    vector<bool>visited(v);
    vector<int>dist(v);
    for(int i=0;i<v;i++)dist[i]=INT32_MAX;
    for(int i=0;i<v;i++)visited[i]=false;
    queue<int> q;
    q.push(src);
    visited[src]=true;
    dist[src]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto e:adl[cur])
        {
            if(!visited[e])
            {
                dist[e]=dist[cur]+1;
                q.push(e);
                visited[e]=true;
            }
        }
    }
    return dist;

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
    int src;
    cout<<"Enter the source from where you want to find the path";
    cin>>src;
    vector<int> dist=findSP(adl,v,src);
    for(int i=0;i<dist.size();i++)
    {
        if(dist[i]!=INT32_MAX)
        cout<<src<<"->"<<i<<" dist= "<<dist[i]<<endl;
        else
        {
            cout<<src<<"->"<<i<<" Not connected!"<<endl;
        }
        
    }
    return 0;
}