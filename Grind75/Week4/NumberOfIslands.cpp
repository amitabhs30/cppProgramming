// 200. Number of Islands
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3



// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 300
//     grid[i][j] is '0' or '1'.
//
#include <string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_set<string> visited;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]=='1'&&visited.find(to_string(i)+","+to_string(j))==visited.end()){
                    islands+=1;
                    bfs(grid, i, j, directions, visited, rows, cols);
                }
            }
        }
        return islands;
    }
private:
    void bfs(vector<vector<char>>& grid, int r, int c, vector<pair<int, int>> &directions, unordered_set<string> &visited, int rows, int cols){
        queue<pair<int,int>>q;
        q.push(make_pair(r,c));

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto [dr, dc]: directions){
                int nr = row+dr;
                int nc = col+dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && visited.find(to_string(nr) + "," + to_string(nc)) == visited.end()) {
                                    q.push({nr, nc});
                                    visited.insert(to_string(nr) + "," + to_string(nc));
                                }
            }
        }

    }
};
