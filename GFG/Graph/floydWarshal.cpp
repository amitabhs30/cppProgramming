#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > floydWarshall(vector<vector<int> > mat)
{
    vector<vector<int> > dist;

    dist = mat;

    for (int k = 0; k < mat.size(); k++)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

void printResult(vector<vector<int> > dist)
{
    cout<<"All pair shortest path :-"<<endl<<endl;
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist.size(); j++)
        {
            if (dist[i][j] == INT16_MAX)
                cout << "NA"
                     << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout<<endl;
    }
}

int main()
{
    int v, e;
    vector<vector<int> > mat;
    cout << "Enter the no of vertices";
    cin >> v;
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        vector<int> temp(v, INT16_MAX);
        temp[count++] = 0;
        mat.push_back(temp);
    }
    cout << "Enter the no. of edges";
    cin >> e;
    cout << "Enter the edges and weight";
    int v1, v2, w;
    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2 >> w;
        mat[v1][v2] = w;
    }
    printResult(floydWarshall(mat));
    return 0;
}


/*
             10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3      

    
        0 1 5
        0 3 10
        1 2 3
        2 3 1

*/            