#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        for (int i = 0; i<intervals.size();i++){
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            int new_start = newInterval[0];
            int new_end = newInterval[1];
            //check if this overlaps with the new interval:
            // This can be done by checking if the start of new Interval is less than end of current interval
            // and end of new interval is more than start of the current interval.
            if(new_start<=cur_end && new_end>=cur_start){
                newInterval[0] = min(new_start, cur_start);
                newInterval[1] = max(new_end, cur_end);
            }
            else{
                if (cur_end<new_start){
                    results.push_back(intervals[i]);
                }
                else if(new_end<cur_start){
                    results.push_back(newInterval);
                    for(int j = i+1; j<intervals.size(); j++){
                        results.push_back(intervals[j]);
                        return results;
                    }
                }
            }
        }
        results.push_back(newInterval);
        return results;
    }
};
