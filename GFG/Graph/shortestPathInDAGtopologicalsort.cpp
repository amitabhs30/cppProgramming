#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct edge{

    int v;
    int w;
    edge(int x,int y)
    {
        v=x;
        w=y;
    }

};



void addEdge(vector<edge*> adl[],vector<int>&indegree, int v1, int v2,int w)
{
    edge *e=new edge(v2,w);
    adl[v1].push_back(e);
    indegree[v2]++;
}

void BFS(vector<edge*>adl[],vector<int>&indegree,int v,int src,vector<int>&tsort)
{
    queue<int>q;
    q.push(src);
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0&&i!=src)
        q.push(i);
    }
    while(!(q.empty()))
    {
        int tp=q.front();
        tsort.push_back(tp);
        q.pop();
        for(auto x:adl[tp])
        {
            indegree[x->v]--;
            if(indegree[x->v]==0)
            {
                q.push(x->v);
            }
        }

        indegree[tp]--;
    }
}

vector<int>tpsort(vector<edge *> adl[],vector<int>indegree, int v)
{
    vector<int>tsort;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            BFS(adl,indegree,v,i,tsort);
        }
    }
    return tsort;
}

vector<int>findShortestPath(vector<edge*>adl[],vector<int>tsort,int src)
{
    vector<int>dist(tsort.size(),INT16_MAX);
    dist[src]=0;
    for(int i=0;i<tsort.size();i++)
    {
        for(auto x:adl[tsort[i]])
        {
            if(dist[x->v]>dist[tsort[i]]+x->w)
            dist[x->v]=dist[tsort[i]]+x->w;
        }
    }
    return dist;
}


int main()
{

    int v, e,w;

    cout << "Enter the No. of vertices";
    cin >> v;
    vector<edge *> adl[v];
    vector<int>weight(v);
    vector<int>indegree(v,0);
    cout << "Enter the No. of edges";
    cin >> e;
    int v1, v2,src;
    cout << "Enter the Edges";

    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2>>w;
        addEdge(adl,indegree,v1, v2, w);
    }
    cout<<"Enter the source";
    cin>>src;
    vector<int>dist=findShortestPath(adl,tpsort(adl,indegree,v),src);

    for(int i=0;i<dist.size();i++)
    {
        cout<<src<<" to "<<i<<" dist= "<<dist[i]<<endl;
    }
    return 0;
}

/*
0 1 2
0 4 1
4 2 2
1 2 3
4 5 4
2 3 6
5 3 1
*/