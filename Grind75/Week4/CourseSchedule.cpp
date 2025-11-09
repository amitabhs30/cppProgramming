// 207. Course Schedule
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.



// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.



// Constraints:

//     1 <= numCourses <= 2000
//     0 <= prerequisites.length <= 5000
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     All the pairs prerequisites[i] are unique.

#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
    bool dfs(int i ,unordered_map<int, vector<int>> &required ,vector<int>&currentDependent){
        if(required[i].size()==0){
            return true;
        }
        for(auto pre: required[i]){
            if(currentDependent[pre]==1){
                return false;
            }
            else{
                if(currentDependent[pre]==0) continue;
                currentDependent[pre]=1;
                bool result = dfs(pre, required, currentDependent);
                if(!result) return false;
                currentDependent[pre]=0;
            }
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> required;
        vector<int>currentDependent(numCourses, -1);
        for(auto pairs: prerequisites){
                required[pairs[0]].push_back(pairs[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(currentDependent[i]==-1){
                if(!dfs(i, required, currentDependent)){
                    return false;
                }
            }
        }
        return true;
    }
};
