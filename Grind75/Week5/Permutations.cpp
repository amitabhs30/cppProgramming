#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()==1){
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
        }
        vector<int> remainingNums;
        for(int i=0; i<nums.size(); i++){
            int selected = nums[i];
            for(int j = 0; j<nums.size(); j++){
                if(j!=i){
                    remainingNums.push_back(nums[j]);
                }
            }
            vector<vector<int>> remPermutes = permute(remainingNums);
           for(vector<int> remPermute: remPermutes){
               remPermute.insert(remPermute.begin(), selected);
               res.push_back(remPermute);
           }
        }
        return res;
    }
};
