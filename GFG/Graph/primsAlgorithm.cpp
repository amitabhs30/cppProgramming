#include<iostream>
#include<vector>

using namespace std;


int prims(vector<vector<int> >graph){
    int res=0;
    vector<int>key(graph[0].size(),INT16_MAX);
    vector<bool>inMst(graph[0].size(),false);
    key[0]=0;
    for(int i=0;i<graph[0].size();i++)
    {   int u=-1;
        for(int j=0;j<graph[0].size();j++)
        {
            if(!(inMst[j])&&(u==-1||key[j]<key[u]))
                u=j;  
        }
        inMst[u]=true;
        res=res+key[u];
        for(int v=0;v<graph.size();v++)
        {
            if(graph[u][v]!=0&&!(inMst[v]))
            {
                key[v]=min(key[v],graph[u][v]);
            }
        }
    }


    return res;
}


int main()
{
    vector<vector<int> >graph;
    int V,e;
    cout<<"Enter the no. of vertices";
    cin>>V;
    for(int i=0;i<V;i++)
    {
        vector<int>tp(V,0);
        graph.push_back(tp);
    }
    cout<<"Enter the edges";
    cin>>e;
    int v,u,w;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    cout<<"Cost of MST= "<<prims(graph);
    return 0;
}

