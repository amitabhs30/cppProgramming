#include<vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>&result, vector<int>&curCandidates, vector<int>& candidates, int target, int currentSum, int index){
        if(currentSum>target){
             return;
        }
        if(currentSum==target){
            result.push_back(curCandidates);
            return;
        }
        for(int i = index; i< candidates.size(); i++){
            curCandidates.push_back(candidates[i]);
            currentSum+=candidates[i];
            dfs(result, curCandidates, candidates, target, currentSum, i);
            curCandidates.pop_back();
            currentSum-=candidates[i];
        }
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curCandidates;
        dfs(result, curCandidates, candidates, target, 0, 0);
        return result;
    }
};
