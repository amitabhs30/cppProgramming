#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int color;
    vector<Node*>neighbours;
    Node(){
        color=0;
    }
    void addNeighbour(Node *x)
    {
        neighbours.push_back(x);
    }
};

int applyColour(Node *current, int V)
{
    bool foundSameColor=false;
    do{
    current->color=(current->color+1)%V;
    if(current->color==0)
        return 0;
    for(auto x: current->neighbours)
    {   foundSameColor=false;
        if(x->color==current->color)
        {
            foundSameColor=true;
            break;
        }    
    }    
    if(!(foundSameColor))
    {
        return current->color;
    }
    }while(1);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int V,E;
    cin>>V;
    cin>>E;
    vector<Node*>vertices(V);
    for(int i=0;i<V;i++)
    {
        vertices[i]=new Node();
    }
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        vertices[u]->addNeighbour(vertices[v]);
        vertices[v]->addNeighbour(vertices[u]);
    }

    for(int i=0;i<vertices.size();i++)
    {
        applyColour(vertices[i],V);
        if(vertices[i]->color==0)
        {
            cout<<"Not possible to color all nodes!";
            return 0;
        }
    }
    for(int i=0;i<vertices.size();i++)
    {
        cout<<"Vertex "<<i<<" Colour= "<<vertices[i]->color<<endl;
    }
    return 0;
}






/*

    0------1
    \      \     
    \      \     
    \      \     
    2------3

edges - 0 1, 0 2, 1 3, 2 3
0 1
0 2
1 3
2 3
*/