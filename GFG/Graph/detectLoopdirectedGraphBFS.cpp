#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;




void addEdge(vector<int> adl[],vector<int>&indegree, int v1, int v2)
{
    adl[v1].push_back(v2);
    indegree[v2]++;
}

void BFS(vector<int>adl[],vector<int>&indegree,int v,int src)
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
        //cout<<tp<<" ";
        q.pop();
        for(auto x:adl[tp])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }

        indegree[tp]--;
    }
}

void findSource(vector<int> adl[],vector<int>indegree, int v)
{
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            BFS(adl,indegree,v,i);
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i]>0)
        {
            cout<<"cycle is present";
            return;
        }
    }
    cout<<"No cycle present";
}




int main()
{

    int v, e;

    cout << "Enter the No. of vertices";
    cin >> v;
    vector<int> adl[v];
    vector<int>indegree(v,0);
    cout << "Enter the No. of edges";
    cin >> e;
    int v1, v2;
    cout << "Enter the Edges";



    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;
        addEdge(adl,indegree,v1, v2);
    }

    findSource(adl,indegree,v);
    return 0;
}