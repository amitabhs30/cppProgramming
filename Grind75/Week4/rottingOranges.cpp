#include <utility>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>queue;
        int fresh_count = 0;
        for(int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    queue.push(make_pair(i, j));
                }
                else if(grid[i][j]==1){
                    fresh_count+=1;
                }
            }
        }
        if(fresh_count == 0)
            return 0;
        int steps = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        while(!queue.empty()){
            int size = queue.size();
            if(fresh_count == 0)
                return steps;
            for(int i=0; i<size; i++){
                int x = queue.front().first;
                int y = queue.front().second;
                queue.pop();
                for(int j=0; j<4; j++){
                    if (x+dx[j]>=0 && x+dx[j]<grid.size()&&y+dy[j]>=0 && y+dy[j]<grid[0].size()){
                        if(grid[x+dx[j]][y+dy[j]]==1){
                            fresh_count-=1;
                            grid[x+dx[j]][y+dy[j]]=2;
                            queue.push(make_pair(x+dx[j],y+dy[j]));
                        }
                    }
                }
            }
            steps+=1;
        }
        return -1;
    }
};
