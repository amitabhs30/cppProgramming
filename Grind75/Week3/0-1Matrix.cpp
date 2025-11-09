// 542. 01 Matrix
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.



// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]



// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 104
//     1 <= m * n <= 104
//     mat[i][j] is either 0 or 1.
//     There is at least one 0 in mat.



// Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/
#include <utility>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> processed;
        vector<vector<int>> result = {0,vector<int>{0}};
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    processed.push(make_pair(i,j));
                }
            }
        }
        int dx[4]={1, 0, -1, 0};
        int dy[4]={0, 1, 0, -1};
        while(!processed.empty()){
            int x = processed.front().first;
            int y = processed.front().second;
            processed.pop();
            for(int i=0; i<4; i++){
                if(x+dx[i]>=0 && x+dx[i]<mat.size()&&y+dy[i]>=0&&y+dy[i]<mat[0].size()){
                    mat[x+dx[i]][y+dy[i]] = mat[x][y]+1;
                    processed.push(make_pair(x+dx[i], y+dy[i]));
                }
            }
        }
        return mat;
    }
};
